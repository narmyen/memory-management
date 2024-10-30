#include <stdio.h>
#include <stdlib.h>  // สำหรับ malloc

// Global variables อย่างน้อย 3 ตัว
int global1 = 10;
int global2 = 20;
int global3 = 30;

// ฟังก์ชัน recursive ที่มีการเรียกซ้อนกันอย่างน้อย 3 ชั้น
void recursiveFunction(int n) {
    if (n > 0) {
        int localVariable = n;  // ตัวแปร local ที่จะอยู่ใน stack memory
        printf("Recursive Call %d: Local Variable Address = %p\n", n, (void*)&localVariable);
        recursiveFunction(n - 1);  // เรียกตัวเอง (recursion)
    }
}

// ฟังก์ชันสำหรับการใช้ malloc เพื่อจองหน่วยความจำบน heap
void useMalloc() {
    // จองหน่วยความจำสำหรับ 3 ตัวเลข
    int *heapMemory = (int *)malloc(3 * sizeof(int));  
    if (heapMemory == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");  // ใช้ stderr สำหรับข้อความแสดงข้อผิดพลาด
        return;
    }

    // กำหนดค่าในหน่วยความจำที่ถูกจองและแสดง address
    for (int i = 0; i < 3; i++) {
        heapMemory[i] = (i + 1) * 10;  // กำหนดค่า
        printf("Heap Memory [%d]: Address = %p, Value = %d\n", i, (void*)&heapMemory[i], heapMemory[i]);
    }

    free(heapMemory);  // คืนหน่วยความจำ
}

int main() {
    // แสดงที่อยู่และค่าของตัวแปร global
    printf("Global Variables:\n");
    printf("Address of global1 = %p, Value = %d\n", (void*)&global1, global1);
    printf("Address of global2 = %p, Value = %d\n", (void*)&global2, global2);
    printf("Address of global3 = %p, Value = %d\n", (void*)&global3, global3);

    printf("\nCalling recursive function:\n");
    recursiveFunction(3);  // เรียกฟังก์ชัน recursion อย่างน้อย 3 ชั้น

    printf("\nUsing malloc to allocate memory:\n");
    useMalloc();  

    return 0;
}
