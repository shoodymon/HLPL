// Lab_2p.go
package main

import (
	"fmt"
)

type Person struct {
	Id   int
	Name string
	Age  int
}

func (a Person) Info() string {
	return fmt.Sprintf("Id: %d, Name: %s, Age: %d", a.Id,
		a.Name, a.Age)
}

func main() {
	persons := [5]Person{
		{1, "Bill", 25},
		{2, "Caro", 13},
		{3, "Stasyao", 32},
		{4, "Rico", 44},
		{5, "Peter", 51},
	}
	for _, person := range persons {
		fmt.Println(person.Info())
	}
}
