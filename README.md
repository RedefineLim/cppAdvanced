
# PyTorch神经网络代码详细批注

## 导入库部分

```python
import torch
import torch.nn as nn
import torch.nn.functional as F

from ncps.torch import CfC, LTC
from ncps.wirings import AutoNCP, NCP
import matplotlib.pyplot as plt
import seaborn as sns
```

- **导入PyTorch基础库**：用于构建和训练神经网络
- **导入ncps库**：包含神经环路处理器(Neural Circuit Policies)相关组件
    - CfC: 是Closed-form Continuous-time RNN单元
    - LTC: 是Liquid Time-Constant网络
    - AutoNCP/NCP: 神经环路处理器的自动/手动布线工具
- **导入可视化工具**：matplotlib和seaborn用于绘制网络结构图


## 设备配置

```python
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
```

- 检测是否有CUDA设备可用，有则使用GPU加速，否则使用CPU


## LNN类（结合CNN和NCP的网络）

```python
class LNN (nn.Module):
    def __init__(self, ncp_input_size, hidden_size, num_classes, sequence_length):
        super(LNN, self).__init__()

        self.hidden_size = hidden_size
        self.ncp_input_size = ncp_input_size
        self.sequence_length = sequence_length
```

- **LNN类初始化**：继承自nn.Module
- **参数保存**：记录隐藏层大小、NCP输入大小和序列长度


### CNN部分（特征提取）

```python
        ### CNN HEAD
        self.conv1 =  nn.Conv2d(1,16,3) # 输入通道1, 输出通道16, 卷积核3x3
        self.conv2 =  nn.Conv2d(16,32,3, padding=2, stride=2)
        self.bn2 = nn.BatchNorm2d(32)
        self.conv3 =  nn.Conv2d(32,64,5, padding=2, stride=2)
        self.conv4 =  nn.Conv2d(64,128,5, padding=2, stride = 2)
        self.bn4 = nn.BatchNorm2d(128)
```

- **卷积层堆叠**：共4个卷积层，逐步增加通道数（1→16→32→64→128）
- **批归一化**：在第2和第4卷积层后添加批归一化，提高训练稳定性
- **卷积特点**：后三层使用stride=2进行下采样，部分使用padding保持特征图尺寸


### NCP架构（神经环路处理器）

```python
        ### DESIGNED NCP architecture
        wiring = AutoNCP(hidden_size, num_classes)    # 234,034 parameters

        # wiring = NCP(
        #     inter_neurons=13,  # 中间神经元数量
        #     command_neurons=4,  # 命令神经元数量
        #     motor_neurons=2,  # 运动神经元数量
        #     sensory_fanout=4,  # 每个感觉神经元的输出突触数量
        #     inter_fanout=2,  # 每个中间神经元的输出突触数量
        #     recurrent_command_synapses=3,  # 命令神经元层中的循环突触数量
        #     motor_fanin=4,  # 每个运动神经元的输入突触数量
        # )
        self.rnn = CfC(ncp_input_size, wiring)

        make_wiring_diagram(wiring, "kamada")
```

- **自动NCP配置**：使用AutoNCP自动配置神经环路处理器布线
- **注释掉的手动配置**：展示了如何手动定义NCP布线（更精细的控制）
- **CfC RNN**：使用Closed-form Continuous-time RNN作为循环单元
- **可视化**：调用函数生成网络布线图，使用"kamada"布局算法


### 前向传播方法

```python
    def forward(self, x):
        # x = F.max_pool2d(F.relu(self.conv1(x)), (2,2))
        # x = F.max_pool2d(F.relu(self.conv2(x)), (2,2))

        x = F.relu(self.conv1(x))
        x = F.relu(self.bn2(self.conv2(x)))
        x = F.relu(self.conv3(x))
        x = F.max_pool2d(F.relu(self.bn4(self.conv4(x))), (2,2))
        
        ## RNN MODE
        x = x.view(-1, self.sequence_length, self.ncp_input_size)
        h0 = torch.zeros(x.size(0), self.hidden_size).to(device)

        out, _ = self.rnn(x, h0)
        out = out[:, -1, :]   # 序列中每部分都生成输出，分类任务只需要最后一个时刻的输出
        return out
```

- **CNN特征提取**：通过4个卷积层进行处理，应用ReLU激活和批归一化
- **形状重塑**：将卷积输出重塑为(批大小, 序列长度, 特征大小)以适配RNN
- **初始化隐藏状态**：创建全零初始隐藏状态
- **RNN处理**：通过CfC处理序列数据
- **选择输出**：只保留最后一个时间步的输出用于分类


## 绘制布线图函数

```python
def make_wiring_diagram(wiring, layout):
    sns.set_style("white")
    plt.figure(figsize=(12, 12))
    legend_handles = wiring.draw_graph(layout=layout,neuron_colors={"command": "tab:cyan"})
    plt.legend(handles=legend_handles, loc="upper center", bbox_to_anchor=(1, 1))
    sns.despine(left=True, bottom=True)
    plt.tight_layout()
    plt.show()
```

- **函数功能**：可视化NCP的布线结构
- **样式设置**：使用白色背景，命令神经元用青色标记
- **绘图过程**：调用wiring对象的draw_graph方法，添加图例和美化设置


## DNN类（全连接深度网络）

```python
class DNN(nn.Module):   # 935,298 parameters
    def __init__(self, img_size):
        super(DNN, self).__init__()
        self.img_size = img_size
        self.fc1 = nn.Linear(img_size, 64 * 4 * 4)
        self.fc2 = nn.Linear(64 * 4 * 4, 128) 
        self.fc3 = nn.Linear(128, 2)

    def forward(self, x):
        x = x.view(-1, self.img_size)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x
```

- **简单全连接网络**：包含三个线性层的深度神经网络
- **参数数量**：约93.5万参数
- **网络结构**：
    - 输入层→展平
    - 第一全连接层(img_size→1024)→ReLU
    - 第二全连接层(1024→128)→ReLU
    - 输出层(128→2)
- **适用于**：简单的二分类任务


## CNN_Net类（经典卷积神经网络）

```python
class CNN_Net(nn.Module):
    def __init__(self, in_channels, num_classes):
        super(CNN_Net, self).__init__()
        
        # 各卷积层定义...

    def forward(self, x):
        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)
        x = self.layer5(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x
```

- **经典CNN架构**：包含5个卷积层块和3个全连接层
- **每个卷积块**：卷积+批归一化+ReLU激活（部分包含最大池化）
- **特征通道变化**：in_channels→16→16→64→64→64
- **全连接部分**：
    - 展平→1024→128→128→num_classes
- **设计特点**：使用Sequential容器简化层组织，批归一化提高稳定性


## 总体代码结构

这段代码呈现了三种不同的神经网络架构：

1. **LNN**：结合CNN特征提取和基于神经环路处理器的RNN，适用于序列分析
2. **DNN**：简单的全连接网络，适用于基础分类任务
3. **CNN_Net**：标准卷积神经网络，适用于图像分类任务

这些模型可能用于比较不同架构在特定任务上的性能表现，尤其是测试神经环路处理器在序列数据处理方面的优势。

