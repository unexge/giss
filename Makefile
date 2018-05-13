build:
	jbuilder build main.exe

run: build
	./_build/default/main.exe
