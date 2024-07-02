# Welcome to Shopping Cart

This is where you can start to get familiar with the problem and what you need to run it.
This codebase is used during pairing session for JOI initiative.
It's focused on identifying code smells, refactoring and testing legacy codebase while promoting
conversations.

## Problem statement

We have an existing shopping cart application, with a small set of eCommerce/shopping cart rules.
Rules include calculation of total price, discount and loyalty points calculation.
Most of the business logic is implemented in single function shopping_cart_checkout.

## Technologies used

- A C compiler like GCC or Clang with support for C99.
- [Meson](https://mesonbuild.com/).
- [Unity Testing Framework](https://github.com/ThrowTheSwitch/Unity)

## Before the interview

Get familiar with the codebase!
Make sure you have the necessary dependencies installed, and that you are able to run the tests.

## Initial setup

```console
mkdir -v ./build
meson setup ./build
```

## Run tests

```console
meson test -C ./build
```

## Build

```console
meson compile -C ./build
```

## Run the sample application

To understand how this library would be used you can check the `main` method in the `src/main.c` file.
If you want to see the results, run:

```console
./build/joi_grad_shopping_cart_c
```

## Existing business rules

Application code currently implements the following functionality:

- Calculates total price and total loyalty points earned by the customer.
- Products with product code starting with DIS_10 have a 10% discount applied.
- Products with product code starting with DIS_15 have a 15% discount applied.
- Loyalty points are earned more when the product is not under any offer.
  - Customer earns 1 point on every \$5 purchase.
  - Customer earns 1 point on every \$10 spent on a product with 10% discount.
  - Customer earns 1 point on every \$15 spent on a product with 15% discount.
