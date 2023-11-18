# coding >.<

#### Инструкция к папкам:

> - **OPT** — _папка со всем важным_
> - **TEST** — _папка с тестами_ (+тестирующая система)
> - **SETUP** — _подготавливает main к работе_

#### Команды:

> - **`run`** - запускает тестирование
> - **`end`** - очищает тесты
> - **`setup`** - вставить `simple.cpp` в `main.cpp`

    alias run="python3 TEST/build.py"
    alias end="python3 TEST/clear.py"
    alias setup="python3 SETUP/setup.py"
