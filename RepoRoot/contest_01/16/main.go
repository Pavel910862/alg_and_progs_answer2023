// Сглаживание графика погоды
package main

import (
	"fmt"
	"strings"
)

func main() {

	var avrg float64
	var max, n int
	fmt.Scan(&max)
	first_v := make([]int, max) // создали динамический массив
	second_v := make([]float64, n)

	for count := 0; count < len(first_v); count++ {
		fmt.Scan(&first_v[count])
	}
	second_v = append(second_v, float64(first_v[0]))

	for i := 1; i < max-1; i++ {
		avrg = (float64(first_v[i-1]) + float64(first_v[i]) + float64(first_v[i+1])) / 3
		second_v = append(second_v, avrg)
	}
	second_v = append(second_v, float64(first_v[max-1]))

	//for _, j := range first_v { // вывод массива через for
	//	fmt.Println(j)
	//}

	//fmt.Println(strings.Trim(fmt.Sprint(first_v), "[]")) // вывод в строку без скобок

	fmt.Println(strings.Trim(fmt.Sprint(second_v), "[]"))
}

