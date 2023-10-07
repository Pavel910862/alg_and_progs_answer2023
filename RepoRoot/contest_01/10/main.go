package main

import (
	"fmt"
)

func main() {

	var a, b, c string

	fmt.Scan(&a, &b, &c)
	if a == "Нет" && b == "Нет" && c == "Нет" {
		fmt.Print("Кот")
	}else if a == "Нет" && b == "Нет" && c == "Да"{
		fmt.Print("Жираф")
	}else if a == "Нет" && b == "Да" && c == "Нет"{
		fmt.Print("Курица")
	}else if a == "Нет" && b == "Да" && c == "Да"{
		fmt.Print("Страус")
	}else if a == "Да" && b == "Нет" && c == "Нет"{
		fmt.Print("Дельфин")	
	}else if a == "Да" && b == "Нет" && c == "Да"{
		fmt.Print("Плезиозавры")
	}else if a == "Да" && b == "Да" && c == "Нет"{
		fmt.Print("Пингвин")
	}else if a == "Да" && b == "Да" && c == "Да"{
		fmt.Print("Утка")
	}else {fmt.Print("Некоректные данные!")}
}
