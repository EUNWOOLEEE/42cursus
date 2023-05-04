#!/bin/bash

# 입력 파일
infile="infile"

# 출력 파일
outfile="outfile"


echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test1 : grep "h" | tr 'h' 'z'"
./pipex "${infile}" "grep \"h\"" "tr 'h' 'z'" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test2 : ls -l | head -3"
./pipex "${infile}" "ls -l" "head -3" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test3 : catt | ls -l (Invalid first command)"
./pipex "${infile}" "ls -l" "head -3" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test4 : ls -l | catt (Invalid second command)"
./pipex "${infile}" "ls -l" "catt" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test5 : \"\" | ls -l (Empty command)"
./pipex "${infile}" "" "ls -l" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test6 : cat | ls -l (Infile error)"
chmod 000 ${infile}
./pipex "${infile}" "cat" "ls -l" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi
chmod 777 ${infile}

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test7 : ls -l | cat (Outfile error)"
touch ${outfile}
chmod 000 ${outfile}
./pipex "${infile}" "ls -l" "cat" "${outfile}"
if [ -f "${outfile}" ]
then
	chmod 777 ${outfile}
	cat "${outfile}"
	rm ${outfile}
fi


# bonus
echo -e "\n\n\n♡⑅·*˖·. bonus .·˖*·⑅♡"

echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test8 : grep \" \" | wc -l | cat -e"
./pipex "${infile}" "grep \" \"" "wc -l" "cat -e" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi

echo -e "\n\n* ੈ✩‧₊˚* ੈ✩‧₊ test9 : cat -e | cat -e | tr -d '$'"
./pipex "${infile}" "cat -e" "cat -e" "tr -d '$'" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi


# here_doc
echo -e "\n\n\n♡⑅·*˖·. here_doc .·˖*·⑅♡"

echo -e "\n* ੈ✩‧₊˚* ੈ✩‧₊ test10 : wc -l | cat -e | cat -e"
echo -e "* ੈ✩‧₊˚* ੈ✩‧₊ Limiter : END"
./pipex here_doc END "wc -l" "cat -e" "cat -e" "${outfile}"
if [ -f "${outfile}" ]
then
	cat "${outfile}"
	rm ${outfile}
fi
