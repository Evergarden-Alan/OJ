# 目录

## 数据结构

### 线性表

该文件夹下使用数组与链表两种结构实现了线性表/向量（vector）

### 栈

1. stack_link.cpp实现链式栈✅25-3-23
2. stack_vector.cpp实现了线性栈✅25-3-23
3. stack_STL.cpp调用STL的stack✅25-3-23

### 队列

1. queue_vector.cpp实现了线性队列，方向为左进右出✅25-3-29
2. queue_vector2.cpp实现了线性队列，方向为右进左出✅25-3-29
3. queue_double_stack.cpp实现了双栈模拟队列✅25-3-29
4. queue_deque.cpp练习了STL的双端队列使用✅25-3-29
5. queue_STL.cpp练习了STL的队列使用✅25-3-29
6. queue_cycle.cpp实现了循环队列✅25-3-29

## 链表

1. linked_list.cpp实现了单向链表、双向链表、单向循环链表、双向循环链表✅25-3-30
2. TODO，从OIWIKI了解到异或链表，尝试实现✅25-3-30
原理为：
       1. 异或运算满足交换律
       2. 0^x=x
       3. x^x=0
       4. 所以对于两个相邻的节点a^b=c，a^c=b，b^c=a，从而实现了单向遍历时前后指针的交换，使用一个指针的空间，部分实现了双向链表的功能。
缺点为：
       1. 无法实现随机访问，只能单向遍历
       2. 无法实现随机插入、删除
       3. 无法实现随机访问，只能单向遍历

### 树

1. tree.cpp中使用链式存储实现了：

       1. 创建BST✅25.3.15
       2. 先序、中序、后序遍历的递归实现✅25.3.15
       3. 先序+中序的唯一二叉树重建✅25.3.16

## 算法

1. 习题1-13，power2BF_I()
2. 习题1-14，power2()
3. 习题1-15，maxNum()
4. 选择排序平移版链表实现✅25.3.31
5. 数组删除元素✅25.4.06

## OJ

1. 基础普及模板✅25.3.22
2. OIWiKi在队列部分给出的例题，自己实现的方式有问题，待解决✅25.3.29
