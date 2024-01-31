package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

// Начало 

//Функция isPalindrome принимает входную строку и возвращает логическое значение, 
// указывающее, является ли входная строка палиндромом
func isPalindrome(input string) bool { 
	max_i := len(input) / 2 // вычисляем максимальный индекс для выполнения цикла на основе длины входной строки
	if len(input)%2 != 0 {
		max_i++
	}
	ok := true
	lowInput := strings.ToLower(input) // преобразует входную строку в нижний регистр, используя strings.ToLower.
	lowInput = regexp.MustCompile(`[~!@#%^&*() ]+`).ReplaceAllString(lowInput, "") // удаляем не буквенно-цифровые символы из входной строки
	if lowInput == "" {
		return true
	}
	for i := 0; i < max_i; i++ { // выполняем итерацию по символам входной строки, сравнивая символы из начала и конца строки, чтобы проверить на палиндромичность.
		if lowInput[i] != lowInput[len(lowInput)-i-1] { // Если  несоответствие, устанавливаем ok в значение false и выходим из цикла.
			ok = false
			break
		}
	}
	return ok
}

// Конец

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n') // 
	//fmt.Println("read")
	if isPalindrome(line[:len(line)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

