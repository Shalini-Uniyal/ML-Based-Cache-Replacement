# ML-Based-Cache-Replacement
Machine Learning Based Cache Replacement in Linux Kernel using Decision Tree Classifier

This project implements a **Machine Learning–based cache replacement policy** using a **Decision Tree Classifier** to enhance how an operating system manages memory pages.  
Unlike traditional static algorithms like **LRU (Least Recently Used)**, this approach adapts dynamically to changing access patterns, improving overall cache efficiency and reducing page faults.

---

##  Overview

Modern operating systems use cache replacement algorithms to decide which memory pages to retain or evict.  
However, algorithms such as **LRU** or **FIFO** are predefined and cannot adapt to user behavior or workload variations.

This project introduces an **intelligent ML-driven approach** that learns from real cache access data to predict whether a page is likely to be reused, optimizing memory management and system performance.

---

##  Why It’s Beneficial

-  **Adaptive Learning:** Learns from actual access patterns instead of following fixed logic.  
-  **Higher Efficiency:** Reduces unnecessary page replacements, improving cache hit ratio.  
-  **Data-Driven Decisions:** Uses kernel-generated data to guide eviction policies.  
-  **Optimized Resource Use:** Frees cache intelligently while keeping frequently used pages.  

By integrating **machine learning** into the Linux kernel, this system demonstrates how AI can optimize low-level operating system behavior.

---

##  How It Works

1. **Data Logging**  
   - Modified `mm/vmscan.c` in the Linux kernel to log key parameters: reference bit, dirty status, age, and access count.  

2. **Dataset Creation**  
   - Exported these logs to a `.csv` file and labeled each entry as *reused* or *not reused*.  

3. **Model Training**  
   - Trained a **Decision Tree Classifier** in Python to predict the likelihood of page reuse.  

4. **Kernel Integration**  
   - Translated the trained model into C logic and embedded it into the kernel’s page replacement function.  

5. **Testing & Evaluation**  
   - Tested the updated kernel on **Ubuntu VirtualBox**, comparing results with LRU in terms of cache hits, page faults, and performance.  

---

##  Objective

To build a **smart, adaptive cache replacement mechanism** capable of:
- Predicting which pages will be reused  
- Reducing page faults  
- Enhancing cache performance through machine learning  

---

##  Tech Stack

- **Python** – Model training (Decision Tree)  
- **C Language** – Kernel modification and integration  
- **Ubuntu VirtualBox** – Testing environment  
- **CSV Dataset** – Data collection and preprocessing  

---

##  Results

The ML-based replacement policy:
- Increased **cache hit ratio**  
- Reduced **page faults**  
- Improved overall **system responsiveness** compared to traditional LRU and FIFO algorithms  

---

##  Author

**Shalini Uniyal**    

---


