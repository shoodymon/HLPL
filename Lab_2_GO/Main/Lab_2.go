// Lab_2.go
package main

import (
	"fmt"
)

// Определяем структуру Animal
type Animal struct {
	Name    string
	Species string
	Age     int
}

// Метод для вывода информации о животном
func (a Animal) Info() string {
	return fmt.Sprintf("Name: %s, Species: %s, Age: %d", a.Name,
		a.Species, a.Age)
}

func main() {
	// Создаем массив из 5 животных
	animals := [5]Animal{
		{"Leo", "Lion", 5},
		{"Milo", "Dog", 3},
		{"Whiskers", "Cat", 2},
		{"Polly", "Parrot", 4},
		{"Goldie", "Goldfish", 1},
	}
	// Выводим информацию о каждом животном
	for _, animal := range animals {
		fmt.Println(animal.Info())
	}
}
