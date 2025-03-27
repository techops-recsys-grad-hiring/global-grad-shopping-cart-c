# Welcome to Shopping Cart


*Read this in other languages: [English](README.md), [Português do Brasil](README.pt-br.md).*

This is where you can start to get familiar with the problem and what you need to run it.
This codebase is used during pairing session for JOI initiative.
It's focused on identifying code smells, refactoring and testing legacy codebase while promoting
conversations.

## Problem Statement

We have an existing shopping cart application, with a small set of eCommerce/shopping cart rules. Rules include calculation of total price, discount and loyalty points calculation. Most of the business logic is implemented in single function shopping_cart_checkout.

## Technology used

- C99
- CMake - build tool
- Conan - dependency management
- CUnit - unit testing framework

## Before the interview

Get familiar with the codebase! Make sure you have the necessary dependencies installed, and that you are able to run the tests.

## What you need to run it

- C++ Compiler
- [Conan](https://conan.io/downloads.html)
- [Cmake](https://cmake.org/download/)

## Install Dependency
```console
conan profile detect --force
conan install . --output-folder=build --build=missing
```

## Build

```console
cmake --preset conan-release
cmake --build build
```

## Run Tests

```console
cd build
./joi_grad_shopping_cart_c_test
```

## Run the Sample Application

To understand how this library would be used you can check the `main` method in the `src/main.c` file. If you want to see the results, run:

```console
cd build
./joi_grad_shopping_cart_c
```

## Existing Business Rules

Application code currently has following rules:

- Calculates total price and total loyalty points earned by the customer.
- Products with product code starting with DIS_10 have a 10% discount applied.
- Products with product code starting with DIS_15 have a 15% discount applied.
- Loyalty points are earned more when the product is not under any offer.
  - Customer earns 1 point on every \$5 purchase.
  - Customer earns 1 point on every \$10 spent on a product with 10% discount.
  - Customer earns 1 point on every \$15 spent on a product with 15% discount.
