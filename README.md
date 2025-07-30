# 🔥 Buffer Overflow Demo – Stack Exploitation in C

This project demonstrates a **classic stack-based buffer overflow vulnerability** in C, where an input overflows a character buffer and overwrites a nearby `int` variable (`is_admin`). This can result in **privilege escalation** and mimics a compiler bug where the **first character is written before an integer**, leading to corruption of adjacent stack variables.

> ⚠️ This project is for **educational purposes only**. Do **not** use these techniques on unauthorized systems.

---

## 🛠 Features

- Vulnerable function with `strcpy()` and no bounds checking
- Overflowing `char buffer[8]` affects adjacent `int is_admin`
- Shows how stack memory can be manipulated
- Demonstrates old GCC 3.x stack layout behavior
- GDB-compatible for detailed memory analysis

---

## 📁 File Structure

vuln_buffer_project/
├── main.c # Main vulnerable C program
├── Makefile # Compiler instructions
└── README.md # Project documentation

yaml
Copy
Edit

---

## 🧠 Concept

The vulnerable function:

```c
void process_input(char *user_input) {
    char buffer[8];
    int is_admin = 0;
    strcpy(buffer, user_input);  // Overflows buffer if input > 8 bytes
}
