package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Начало 
// принимает строку ввода и возвращает булево значение, указывающее, является ли число "счастливым".
func isLucky(input string) bool {
	first, second := 0, 0
	for _, sym := range input[:3] { // разделяем входную строку на две части: первые три символа и оставшиеся символы
		temp, _ := strconv.Atoi(string(sym)) // преобразует каждый символ в число...
		first += temp // ... и суммирует их для обеих частей
	}
	for _, sym := range input[3:] { // Возвращает true, если сумма первых трех символов равна сумме оставшихся символов, ...
		temp, _ := strconv.Atoi(string(sym)) // ... иначе возвращает false
		second += temp
	}
	return first == second
}

// Конец

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

