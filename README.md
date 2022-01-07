[![Actions status](https://github.com/matumoto1234/otouto-interpreter/actions/workflows/iutest.yml/badge.svg)](https://github.com/matumoto1234/otouto-interpreter/actions/)

# otouto-interpreter

実は兄はいました

imouto じゃなくて otouto なのは特に理由はないです


## make コマンド
```bash
# オブジェクトファイルの生成(コンパイル)
$ make build

# ファイルを限定したコンパイル
# $(FILE)のコンパイルを行います
$ make only-build FILE=./src/tests/interpreter.test.cpp

# オブジェクトファイル、実行ファイルの削除
$ make clean

# テストを実行
# $(TARGET).test.cppが適用されます
$ make test TARGET=interpreter

# clean build test のエイリアス
$ make all TARGET=parser-types
```