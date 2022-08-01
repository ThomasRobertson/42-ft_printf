
<h1 align="center">
  ft_printf
  <br>
</h1>

<h4 align="center">Like printf(), just worse.
<br>
<br>
</h4>

<p align="center">
  <a href="https://github.com/ThomasRobertson/42-ft_printf">
    <img src="https://tokei.rs/b1/github/ThomasRobertson/42-ft_printf"
         alt="Line of Code">
  </a>
  <a href="https://github.com/ThomasRobertson/42-ft_printf">
    <img src="https://img.shields.io/github/languages/code-size/ThomasRobertson/42-ft_printf"
         alt="Size">
  </a>
  <a href="https://github.com/ThomasRobertson/42-ft_printf">
    <img src="https://img.shields.io/github/languages/top/ThomasRobertson/42-ft_printf"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-ft_printf">
    <img src="https://img.shields.io/github/license/ThomasRobertson/42-ft_printf"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-ft_printf/actions/workflows/norminette-action.yml">
    <img src="https://github.com/ThomasRobertson/42-ft_printf/actions/workflows/norminette-action.yml/badge.svg"
         alt="Norminette Action">
  </a> 
</p>

<p align="center">
  <a href="#summary">Summary</a> •
  <a href="#how-it-work">How It Work</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#license">License</a>
</p>

## Summary

This function recreates part of printf(). It uses the same system of conversion, but only support "cspdiuxX%".

It does not support any flags.

> This project is part of 42 Paris' curriculum. You can check the full subject in the subject pdf included in this repo.

## How It Work

This function uses variadic functions to manage an unknown number of arguments.

## How To Use

Clone this GitHub repos

```bash
git clone https://github.com/ThomasRobertson/42-ft_printf
```
Use the provided Makefile to compile the library (using the system's cc)

```bash
make
```
This will create a library, libftprintf.a, containing the function in the libft folder and the ft_printf function.

In the version that was latter integrated into my personal libft, some function names were changed to minimize the risk of collision by integrating this library into a bigger project or with other library.

## License

MIT
