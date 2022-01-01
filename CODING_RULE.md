# コーディング規則

ここにはコーディング規則がのっています


## 命名規則

- ファイル
  スネークケース

- クラス/構造体
  アッパーキャメルケース(パスカルケース)
  ただし、`Hoge_t` のようなものは認める

- 関数/変数/定数
  スネークケース(全て小文字)

- メンバ変数
  `_`を接尾辞とする

- メンバ関数
  キャメルケース


## ファイル構造

```
---/
 |
 |--src/
 |  |
 |  |--modules/
 |  |  |
 |  |  |--evaluators/
 |  |  |--lexical-analyzers/
 |  |  |--parsers/
 |  |  |--evaluator.hpp
 |  |  |--evaluator.cpp
 |  |  |--lexical-analyzer.hpp
 |  |  |--lexical-analyzer.cpp
 |  |  |--parser.hpp
 |  |  |--parser.cpp
 |  |
 |  |--tests/
 |  |  |
 |  |  |--evaluator.test.cpp
 |  |  |--lexical-analyzer.test.cpp
 |  |  |--parser.test.cpp
 |  |  |--interpreter.test.cpp
 |  |
 |  |--interpreter.hpp
 |  |--interpreter.cpp
 |
 |--README.md など
```

なお、`/src/modules/evaluators/`、`/src/modules/lexial-analyzors/`、`/src/modules/parsers/` には該当する `.hpp` と `.cpp` ファイルが入る

- ファイルは `#include` で使用する
  - インターフェース単位の拡張子は`.hpp`
  - 実装単位の拡張子は`.cpp`
  - `module` を使用しない理由
    - g++-11 で private module fragment などが実装されていない (clang++ は知らない)
    - VSCode でインテリジェンスが効かない
      - エラーの波線が大量に出てしまう、予測変換が効かない


## コーディングなど

- できるだけリーダブルコードをもとにしたものにする

- なるべくベストプラクティスに近づける

- バージョンは C++20 (g++-11)

- ヘッダーファイルについて
  - インクルードガードは `#pragma once` を用いる
  - インクルードは最小限にする


## コンパイルと実行

本当なら CMake とかを使って効率的に行いたいけど一旦放置

```bash
# オブジェクトファイルを生成
$ find ./src/modules/ -name *.cpp | xargs g++-11 -c -std=c++20

# バイナリファイルを生成(interpreter.outは好きな名前にする)
$ g++-11 -std=c++20 *.o -o interpreter.out

# 実行
$ ./interpreter.out
```

## テスト

IUTEST を使用

※事前に IUTEST のソースコードをダウンロードしてインクルードパスを通す必要がある


### 手順

1. `tests/` 以下の `.test.cpp` ファイルをコンパイルしてバイナリファイルを生成する
1. 実行

詳しいオプションなどは [公式](https://srz-zumix.github.io/iutest/latest/primer.html) を参照