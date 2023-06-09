# VRender 概述
最后修改日期•2022/12/20
-------
本文档将会介绍 VRender，以及一些相关术语的介绍。

## 什么是 VRender
VRender 是组成 VuiLib 的一个重要部分，是一个基于 Direct2D 的提供 2D 图形渲染能力的 API，在 VuiLib 中，其属于 Core 的子模块 Render，意味着，如果要将 VRender 独立出来使用最好需要将整个 Core 和 Kits 模块独立出来。

> ● 注意：
> 
>     VRender 中的所有对象资源都是线程不安全的，一切线程安全性由用户来进行保证。

## VRender 相关术语

* ## 渲染器资源
  一般地，将所有渲染所需要用到的资源（例如字体，笔刷，图像等）统称为渲染器资源。
* ## 渲染句柄（VRenderHandle）
  渲染句柄（又称渲染上下文），指的是 VRenderHandle 对象，其表示的是一个渲染器的句柄，任何渲染器资源的创建都无法离开渲染句柄，一般而言，一个渲染句柄应该包含两大主要实例：

    1. 渲染器相关对象
    2. 生命周期管理对象（VAllocator）
    
  然而，有的渲染句柄表示的内容可能只有以上两种中的一种，一般都是缺少生命周期管理对象（VAllocator），而使用缺少生命周期管理对象创建的渲染资源创建的渲染资源称为静态渲染器资源，静态渲染器资源资源的生命周期即为整个程序的生命周期（或为当前线程的生命周期），一般地静态渲染器资源都应该是图像、字体而非笔刷。

* ## 静态渲染器资源
   详见上渲染句柄中有关 “静态渲染资器源” 的描述。