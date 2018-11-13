/**
 * Tencent is pleased to support the open source community by making MLeaksFinder available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
 */

#import "NSObject+MemoryLeak.h"
//注释开启MLeakfinder 检测
//#define MEMORY_LEAKS_FINDER_ENABLED 0

//_INTERNAL_MLF_ENABLED 宏用来控制 MLLeaksFinder库
//什么时候开启检测，可以自定义这个时机，默认则是在DEBUG模式下会启动，RELEASE模式下不启动
//它是通过预编译来实现的
#ifdef MEMORY_LEAKS_FINDER_ENABLED
#define _INTERNAL_MLF_ENABLED MEMORY_LEAKS_FINDER_ENABLED
#else
#define _INTERNAL_MLF_ENABLED DEBUG
#endif
//_INTERNAL_MLF_RC_ENABLED 宏用来控制 是否开启循环引用的检测

//注释开启retainCycle 检测
//#define MEMORY_LEAKS_FINDER_RETAIN_CYCLE_ENABLED 0

#ifdef MEMORY_LEAKS_FINDER_RETAIN_CYCLE_ENABLED
#define _INTERNAL_MLF_RC_ENABLED MEMORY_LEAKS_FINDER_RETAIN_CYCLE_ENABLED
//COCOAPODS 因为MLLeaksFinder引用了第三库用来检查循环引用，所以必须是当前项目中使用了COCOAPODS，才能使用这个功能
#elif COCOAPODS
#define _INTERNAL_MLF_RC_ENABLED COCOAPODS
#endif
