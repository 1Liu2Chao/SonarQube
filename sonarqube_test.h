#ifndef SONARQUBE_TEST_H
#define SONARQUBE_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 测试：未使用的宏定义 - squid:S1065
#define UNUSED_MACRO 100

// 测试：魔法数字 - squid:S109
#define MAX_BUFFER_SIZE 1024

// 测试：全局变量 - squid:S1118
int global_variable;

// 函数声明
void memory_leak_test(void);
void buffer_overflow_test(void);
void security_issues_test(void);
void code_smells_test(void);
int dead_code_function(int x); // 测试未使用的函数声明

#endif
