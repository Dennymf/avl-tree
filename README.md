# Сбалансированное AVL-дерево.

### Версия 0.2
- Функция `isEmpty()` - возвращает `true`, если у нас пустое дерево, иначе возвращает `false`. Пример `avl_tree.isEmpty()`
- Функция `erase(value)` - удаляет из дерева вершину с значением `value`. Пример `avl_tree.erase(42)`

### Версия 0.1
- Структура вершины:
  - `T value` - значение
  - `size_t size` - размер поддерева. Для ответа на запрос о размере дерева за `O(1)`
  - `size_t depth` - высота поддерева. Для балансировки
  - `Node* left` - левое поддерево
  - `Node* right` - правое поддерево
- Функция `size()` - возвращает `size_t` размере дерева. Пример `avl_tree.size()`
- Функция `depth()` - возвращает `size_t` высота дерева. Пример `avl_tree.depth()`
- Функция `find(value)` - принимает `value` и возвращает `true`, если элемент есть в дереве, иначе возвращает `false`. Пример `avl_tree.find(42)`
- Функция `insert(value)` - принимает `value` и добавляет его в дерево. Пример `avl_tree.insert(42)`
- Функция `print()` - печатает всё дерево в том порядке, как оно отсортировано. Пример `avl_tree.print()`

```bash
avl-tree
│   .gitattributes
│   .gitignore
│   avl-tree.sln
│   README.md
└───main
    │   avl_tree.h - библиотека с реализацией AVL-дерева
    │   main.cpp - пример работы AVL-дерева
    │   main.vcxproj
    │   main.vcxproj.filters
    │   main.vcxproj.user
```
