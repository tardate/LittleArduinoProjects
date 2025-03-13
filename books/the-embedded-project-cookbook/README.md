# #753 The Embedded Project Cookbook

Book notes: The Embedded Project Cookbook: A Step-by-Step Guide for Microcontroller Projects, by John T. Taylor. Published October 8, 2024.

> Very interesting concept, and very up to date (as of 2024) for C++ based embedded projects.
> Presents a comprehensive project approach, with templates and guidelines for all software-related aspects of the project.

[![Build](./assets/the-embedded-project-cookbook_build.jpg?raw=true)](https://amzn.to/41IQBSh)

## Notes

See also:

* [amazon](https://amzn.to/41IQBSh)
* [goodreads](https://www.goodreads.com/book/show/208896083-the-embedded-project-cookbook)

## Contents

Chapter 1: Introduction

* Software Development Processes
* Software Development Life Cycle
* Outputs and Artifacts
* What You'll Need to Know
* Coding in C and C++
* What Toys You Will Need
* Regulated Industries
* What Is Not Covered
* Conclusion

Chapter 2: Requirements

* Formal Requirements
* Functional vs. Nonfunctional
* Sources for Requirements
* Challenges in Collecting Requirements
* Exiting the Requirements Step
* GM6000
* Summary

Chapter 3: Analysis

* System Engineering
* GM6000 System Architecture
* Software Architecture
* Moving from Inputs to Outputs
* Hardware Interfaces
* Performance Constraints
* Programming Languages.
* Subsystems
* Subsystem Interfaces
* Process Model
* Functional Simulator
* Cybersecurity
* Memory Allocation
* Inter-thread and Inter-process Communication
* File and Directory Organization
* Localization and Internationalization
* Requirement Traceability
* Summary

Chapter 4: Software Development Plan

* Project-Independent Processes and Standards
* Project-Specific Processes and Standards
* Additional Guidelines
* Care and Feeding of Your SDP
* SDP for the GM6000
* Housekeeping
* Roles and Responsibilities
* Software Items
* Documentation Outputs
* Requirements
* Software Development Life Cycle Processes
* Cybersecurity
* Tools
* Software Configuration Management (SCM)
* Testing
* Deliverables
* Summary

Chapter 5: Preparation

* GitHub Projects
* GitHub Wiki
* Continuous Integration Requirements
* Jenkins
* Summary

Chapter 6: Foundation

* SCM Repositories
* Source Code Organizatio
* Build System and Scripts
* Skeleton Applications
* Cl "Build-All" Script
* Software Detailed Design
* Summary

Chapter 7: Building Applications with the Main Pattern

* About the Main Pattern
* Operating System Abstraction Layer
* Hardware Abstraction Layer
* More About Main
* Implementing Main
* Application Variant
* Marketing Abstraction Layer
* Ajax Main and Eros Main
* Build Scripts
* Preprocessor
* Simulator
* The Fine Print
* Summary

Chapter 8: Continuous Integration Builds

* Example Build-All Scripts for GM6000
* The CI Server
* Directory Organization
* Naming Conventions
* Windows `build_all` Script
* Linux `build_all` Script
* Summary

Chapter 9: Requirements Revisited

* Analysis
* Requirements vs. Design Statements
* Design Statement for Control Algorithm
* Design Statement for User Interface
* Missing Formal Requirements.
* Requirements Tracing
* Summary

Chapter 10: Tasks

* 1 - Requirements
* 2 - Detailed Design
* 3 - Source Code and Unit Tests
* 4 - Code Review
* 5 - Merge
* The Definition of Done
* Task Granularity
* Tasks, Tickets, and Agile Summary

Chapter 11: Just-in-Time Detailed Design

* Examples
    * Subsystem Design
    * I2C Driver Design
    * Button Driver Design
    * Fuzzy Logic Controller Design
    * Graphics Library
    * Screen Manager Design
* Design Reviews
* Review Artifacts
* Summary

Chapter 12: Coding, Unit Tests, and Pull Requests

* Check-In Strategies
* Pull Requests
* Granularity
* Examples
* I2C Driver
* Screen Manager
* Summary

Chapter 13: Integration Testing

* Smoke Tests
* Simulator
* Summary

Chapter 14: Board Support Package

* Compiler Toolchain
* Encapsulating the Datasheet
* Encapsulating the Board Schematic
* BSPs in Practice
* Structure
* Dos and Don'ts
* Bootloader
* Summary

Chapter 15: Drivers

* Binding Times
* Public Interface
* Hardware Abstract Layer (HAL)
* Facade
* Separation of Concerns
* Polymorphism
* Dos and Don'ts
* Summary

Chapter 16: Release

* About Builds and Releases
* Tightening Up the Change Control Process
* Software Bill of Materials (SBOM)
* Anomalies List
* Release Notes
* Deployment
* Over-the-Air (OTA) Updates
* QMS Deliverables
* Archiving Build Tools
* Summary

Appendices

* Appendix A: Getting Started with the Source Code
* Appendix B: Running the Example Code
* Appendix C: Introduction to the Data Model Architecture
* Appendix D: Header and LConfig Patterns
* Appendix E: CPL C++ Framework
* Appendix F: NQBP2 Build System
* Appendix G: RATT
* Appendix H: GM6000 Requirements
* Appendix I: GM6000 System Architecture

## RATT

RATT is a Python-based automated test tool built on top of the [`pexpect`](https://github.com/pexpect/pexpect) package

* created to perform automated testing with Units Under Test (UUTs).
* supports a command-line interface, and it can be used with any application that supports interactive behavior with the parent process that launched the application (e.g., stdio).

RATT's features:

* It is a pure Python module that runs on Windows and Linux.
* It has an interactive mode, or it can run automated scripts. Interactive mode support includes listing all available scripts and displaying help for each script.
* Test scripts are written in Python.
* Test scripts can be located anywhere and can be placed in multiple locations in your build tree.

## Outcast

Outcast is an experimental tool suite for managing source code packages for reuse by other packages. Outcast is used to incorporate external repositories such as the CPL C++ class library (colony. core) and NQBP? (nqbpz) into the epc repository so that day-to-day development in the ec is a mono-repository work flow. The Outcast tool only needs to be used when adding or upgrading external packages.

If you need to install the Outcast because you are adding or upgrading external packages, detailed installation instruction for Outcast can be found on the Wiki page: <https://github.com/johnttaylor/epc/wiki/Installing-Developer-Tools:-Development-Machine#outcast> . Make sure you add Outcast's `bin/` directory to the system's command path.

## LHeader and LConfig Patterns

The LHeader and LConfig patterns are two C/C++ patterns that leverage the preprocessor for compile-time binding of interface definitions. The patterns allow creating different flavors of your project based on compile-time settings. While it does add some additional complexity to the structure of your header files and build scripts, it also provides a reliable way to cleanly build multiple variants of your binary.

This appendix describes how to implement and use LHeader and LConfig patterns. A detailed discussion of why you would use these patterns is outside the scope of the book. For an in-depth discussion of the "why" and the importance of late binding times, I refer you to the companion book: Patterns in the Machine: A Software Engineering Guide to Embedded Development.

### LHeader

With the Late Header, or Header, pattern, you defer which header files are actually included until compile time. In this way, the name bindings don't occur until compile time.

### LConfig

The Late Config, or LConfig, pattern is a specialized case of the Header patter that is used exclusively for configuration. The LConfig pattern provides for project-specific header files that contain preprocessor directives or symbol definitions that customize the default behavior of the source code.
