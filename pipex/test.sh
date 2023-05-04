#!/bin/bash

# 입력 파일
infile="infile"

# 출력 파일
outfile="outfile"


echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test1 : grep "h" | tr 'h' 'z'"
./pipex "${infile}" "grep \"h\"" "tr 'h' 'z'" "${outfile}"
cat "${outfile}"

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test2 : ls -l | head -3"
./pipex "${infile}" "ls -l" "head -3" "${outfile}"
cat "${outfile}"

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test3 : catt | ls -l (Invalid first command)"
./pipex "${infile}" "ls -l" "head -3" "${outfile}"
cat "${outfile}"

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test4 : ls -l | catt (Invalid second command)"
./pipex "${infile}" "ls -l" "catt" "${outfile}"
cat "${outfile}"

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test5 : "" | ls -l (Empty command)"
./pipex "${infile}" "" "ls -l" "${outfile}"
cat "${outfile}"


# bonus
echo -e "\n\n\n♡⑅·*˖·.bonus.·˖*·⑅♡"

echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test3 : grep " " | wc -l | cat -e"
./pipex "${infile}" "grep \" \"" "wc -l" "cat -e" "${outfile}"
cat "${outfile}"

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test4 : cat -e | cat -e | tr -d '$'"
./pipex "${infile}" "cat -e" "cat -e" "tr -d '$'" "${outfile}"
cat "${outfile}"


# here_doc
echo -e "\n\n\n♡⑅·*˖·.here_doc.·˖*·⑅♡"

echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test5 : wc -l | cat -e | cat -e"
echo -e "* ੈ✩‧₊˚* ੈ✩‧₊ Limiter : END"
./pipex here_doc END "wc -l" "cat -e" "cat -e" "${outfile}"
cat "${outfile}"
