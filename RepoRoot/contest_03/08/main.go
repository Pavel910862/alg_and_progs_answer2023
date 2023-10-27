package main

import (
	"fmt"
)
// инициализируем переменную result с начальным значением 0. 
//Затем применяем операцию XOR к каждому числу в срезе numbers и результату накапливаем в переменной result. 
//Когда операция XOR применяется к числу с самим собой, результат будет равен 0, 
//поэтому парные числа будут обратно исключены, а число без пары останется.
func findNumberWithoutPair(numbers []int) int {
	result := 0
	for _, num := range numbers {
		result ^= num
	}
	return result
}

func main() {
	var n int
	fmt.Scanln(&n)

	numbers := make([]int, n) // массив размером n
	for i := 0; i < n; i++ {
		fmt.Scan(&numbers[i]) // считываем в массив
	}

	result := findNumberWithoutPair(numbers)
	fmt.Println(result)
}

