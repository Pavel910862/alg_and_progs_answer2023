package main

import (
	"fmt"
	"math"
)

// Начало
// принимает массив целых чисел data и количество шагов steps, на которое нужно сдвинуть элементы массива
func shift(data []int, steps int) {
	temp := make([]int, len(data)) // временный массив temp, копирует в него содержимое массива data
	copy(temp, data)

	realSteps := int(math.Abs(float64(steps))) % len(data) // вычисляем реальное количество шагов realSteps ...
	realSteps = -realSteps                                 // ...как абсолютное значение от steps по модулю длины массива
	if steps < 0 {                                         // Если steps отрицательное, то realSteps тоже делаем отрицательным.
	}
	// выполняем сдвиг элементов массива на realSteps шагов влево или вправо,
	// обрабатываем случаи переполнения индексов
	for i := 0; i < len(data); i++ {
		idx := i - realSteps
		if idx < 0 {
			idx = len(data) + idx
		} else if idx >= len(data) {
			idx -= len(data)
		}
		data[i] = temp[idx]
	}
}

// Конец

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}

