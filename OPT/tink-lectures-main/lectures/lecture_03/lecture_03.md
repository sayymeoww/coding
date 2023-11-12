# Лекция 3

Параллельно с объяснением нужно писать код как пример использования (где это можно сделать).

Рассказать про [cppreference.com](cppreference.com), откуда можно взять информацию про что угодно, связанное с плюсами.

## Контейнеры
Для каждого контейнера базовое устройство, основные методы (вставки (в середину, в конец, в начало), удаления, очистка, поиск элемента), асимптотика основных методов, про итераторы
- [vector](https://en.cppreference.com/w/cpp/container/vector) (также вспомнить про capacity vs size, реаллокация, про [vector<bool>](https://en.cppreference.com/w/cpp/container/vector_bool))
- [map](https://en.cppreference.com/w/cpp/container/map)
- [set](https://en.cppreference.com/w/cpp/container/set)
- [list](https://en.cppreference.com/w/cpp/container/list)
- [unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)/[unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)
- [deque](https://en.cppreference.com/w/cpp/container/deque)
- [bitset](https://en.cppreference.com/w/cpp/utility/bitset)
- [queue](https://en.cppreference.com/w/cpp/container/queue)
- [priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
- [gp_hashtable, cc_hashtable](https://codeforces.com/blog/entry/60737) (по желанию, если время останется, в основном полезно в задачах, где нужно упихать что-то)

## Функции
- lower/upper_bound
- линейные функции, которые сильно упрощают жизнь (fill, reverse, unique, all_of, any_of, none_of, find и т.п.)
- mt19937 и почему rand() это плохо
- компаратор для std::sort и std::set (можно как лямбду, можно как operator())
- range based for (в том числе `for (auto [x, y] : pairs)`), сказать, что это начиная с с++17 и вообще есть разные стандарты и чего-то может не быть в более старых
- рассказать про методы lower_bound и upper_bound в set/map и рассказать про то, что для этих контейнеров нужно использовать только их, так как обычные работают только для конт. с random access итераторами
- конвертация чисел из строк и обратно (to_string, stoi)
- лямбды
- __builtin_popcount(x) (библиотека bit)

## Остальные вещи
- #include <bits/stdc++.h> (плюсы и минусы, то, что не везде работает)
- классы (базовое понимание о том, что они есть, конструктор, методы, переопределение операторов)
- стресс-тестирование (можно в одном файле, можно в разных, расскажем первый вариант)
- __int128 (сказать, что может где-то не работать)
