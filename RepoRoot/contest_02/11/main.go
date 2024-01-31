package main

import "fmt"

const rows int = 9
const cols int = 9

// Начало
func isValidSudoku(board [rows][cols]int) bool {
	// Проверка по строкам и столбцам
	// проходим по каждой строке и столбцу в матрице.
	for i := 0; i < 9; i++ {
		rowMap := make(map[int]bool) // Для каждой строки создаем rowMap, который будет использоваться ...
		colMap := make(map[int]bool) // ...для отслеживания уникальных цифр в этой строке
		for j := 0; j < 9; j++ {
			if board[i][j] != 0 { //Для каждого элемента в строке, если он не равен нулю, проверяем, есть ли он уже в rowMap.
				if rowMap[board[i][j]] {
					return false // Если да, то возвращаем false, так как это означает наличие дубликата.
				}
				rowMap[board[i][j]] = true // Если элемента нет в rowMap, мы добавляем его туда.
			}
			if board[j][i] != 0 {
				if colMap[board[j][i]] {
					return false
				}
				colMap[board[j][i]] = true // Если элемента нет в rowMap, мы добавляем его туда.
			}
		}
	}

	// Проверка по квадратам 3x3
	// проходим по квадрату
	for i := 0; i < 9; i += 3 {
		for j := 0; j < 9; j += 3 {
			squareMap := make(map[int]bool) //  squareMap для отслеживания уникальных цифр
			for k := i; k < i+3; k++ {
				for l := j; l < j+3; l++ {
					if board[k][l] != 0 { // проверяем каждый элемент в квадрате на наличие дубликатов
						if squareMap[board[k][l]] {
							return false
						}
						squareMap[board[k][l]] = true // и добавляем уникальные элементы
					}
				}
			}
		}
	}

	return true
}

// Конец

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

