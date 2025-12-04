#include "sonarqube_test.h"
// 测试1：内存泄漏 - squid:S1274
void memory_leak_test(void) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    if (buffer) {
        strcpy(buffer, "test data");
        printf("Data: %s\n", buffer);
        // 故意不释放内存 - 内存泄漏
        // free(buffer);
    }
}

// 测试2：缓冲区溢出 - squid:S1275
void buffer_overflow_test(void) {
    char small_buffer[10];
    char large_input[] = "This is a very long string that will cause buffer overflow";
    
    // 潜在的缓冲区溢出
    strcpy(small_buffer, large_input);
    
    // 不安全的字符串操作
    char another_buffer[5];
    sprintf(another_buffer, "%s", "overflow");
}

// 测试3：安全相关问题
void security_issues_test(void) {
    // 硬编码密码 - squid:S2068
    char password[] = "my_secret_password_123";
    
    // 使用rand()用于安全目的 - squid:S2245
    int security_token = rand() % 10000;
    
    // 系统命令注入风险 - squid:S2076
    char user_input[100] = "rm -rf /";
    system(user_input);
}

// 测试4：代码坏味道和风格问题
void code_smells_test(int unused_param) { // 未使用的参数 - squid:S1172
    // 过深的嵌套 - squid:S134
    int a = 1, b = 2, c = 3, d = 4;
    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                if (d > 0) {
                    printf("Too deep nesting!\n");
                }
            }
        }
    }
    
    // 重复代码 - squid:S1192
    printf("Same message");
    printf("Same message");
    
    // goto语句 - squid:S1275
    goto label;
    
    // 死代码 - squid:S2583
    printf("This will never be executed");
    
label:
    printf("After goto\n");
    
    // 空的代码块 - squid:S108
    if (a > 10) {
        // 空的if块
    }
      // 魔数 - squid:S109
    int array_size = 100;
    for (int i = 0; i < 100; i++) { // 应该使用具名常量
        // 循环体
    }
}

// 测试5：未使用的函数 - squid:S1172
int dead_code_function(int x) {
    return x * 2;
}

// 测试6：资源泄漏
void resource_leak_test(void) {
    int test1;
    FILE *file = fopen("test.txt", "r");
    if (file) {
        char buffer[100];
        fgets(buffer, 100, file);
        // 故意不关闭文件 - 资源泄漏
        // fclose(file);
    }
}

// 测试7：类型转换问题
void type_conversion_test(void) {
    // 有符号无符号比较 - squid:S1275
    int signed_val = -1;
    unsigned int unsigned_val = 100;
    
    if (signed_val < unsigned_val) { // 可能产生意外结果
        printf("Unexpected comparison result\n");
    }
    
    // 隐式类型转换
    long long_val = 1000;
    int int_val = long_val; // 可能的精度丢失
}

// 测试8：控制流问题
void control_flow_test(int x) {
    // 无限循环 - squid:S1275
    while (1) {
        // 缺少break条件
        sleep(1);
    }
    
    // 重复的条件
    if (x > 0) {
        printf("x is positive\n");
    }
    if (x > 0) { // 重复的条件
        printf("x is still positive\n");
    }
}

// 测试9：复杂的函数
int complex_function(int a, int b, int c, int d, int e, int f) { // 太多参数 - squid:S107
    int result = 0;
    
    // 高圈复杂度 - squid:S1541
    if (a > 0) result += 1;
    if (b > 0) result += 2;
    if (c > 0) result += 3;
    if (d > 0) result += 4;
    if (e > 0) result += 5;
    if (f > 0) result += 6;
    if (a + b > c) result += 7;
    if (b + c > d) result += 8;
    if (c + d > e) result += 9;
    if (d + e > f) result += 10;
    
    switch (result) { // 过大的switch - squid:S1285
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
        case 6: return 6;
        case 7: return 7;
        case 8: return 8;
        case 9: return 9;
        default: return 0;
    }
}

// 测试10：注释和文档问题
/**
 * @brief 缺少参数文档
 */
void poorly_documented_function(int x, int y) {
    // TODO: 实现这个功能 - squid:S1135
    // FIXME: 这里需要修复 - squid:S1135
}

int main(void) {
    printf("SonarQube C Test Code\n");
    
    memory_leak_test();
    buffer_overflow_test();
    security_issues_test();
    code_smells_test(0);
    resource_leak_test();
    type_conversion_test();
    control_flow_test(1);
    complex_function(1, 2, 3, 4, 5, 6);
    
    return 0;
}
