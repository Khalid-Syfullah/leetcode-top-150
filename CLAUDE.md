# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a collection of standalone LeetCode problem solutions written in Java. Each file is a self-contained class with a `main` method that serves as an informal test harness.

## Compiling and Running

Each file compiles and runs independently — there is no build system.

```bash
# Compile a single file
javac FileName.java

# Run it
java ClassName
```

Some files define inner static classes (e.g., `ListNode`, `TreeNode`) locally. Others reference a shared `TreeNode.java` in the same directory.

## Code Patterns

- Each solution class is `public class ClassName` with a `static` solution method and a `main` method that prints expected vs. actual output.
- Some problems have multiple solution files (e.g., `ClimbingStairs.java`, `ClimbingStairs2.java`) exploring different approaches (e.g., DP array vs. space-optimized).
- Data structure helpers (`ListNode`, `TreeNode`, `Node`) are either defined as inner static classes within the file or in standalone files (`TreeNode.java`).
