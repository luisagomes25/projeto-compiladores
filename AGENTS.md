# Repository notes

- This is a single C++17 interpreter; edit `lexer.l` and `parser.y` as the sources of truth for the Flex lexer and Bison parser. `parser.tab.c`/`.h` and `lex.yy.c` are generated.
- `make` builds `oxitona` and then copies it to `oxi` (overwriting that root file). `make test` builds first and runs the 20 regression cases in `testes/casos/`; run one case directly with `./oxitona testes/casos/<file>.oxi`.
- Diagnostics use GCC-style path/line/column output with a source excerpt and caret; `./oxitona --debug arquivo.oxi` (or `-g`) adds raw parser details. Runtime type/name checks happen during interpretation, not in a separate compile phase.
- `make clean` deletes generated parser files and both binaries, including checked-in `parser.tab.c`/`.h`; only use it when you intend to regenerate them with `make`.
