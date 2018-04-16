# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    script.sh                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/16 17:29:55 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2018/04/16 18:25:59 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!bin/bash

# Usage

if  [ $# -eq 0 ]
then
	echo "Usage: ./script.sh -n [number interval] -r [number of repetition]"
	exit
fi

# Get the args

while getopts n:r: option
do
	case "${option}"
		in
		n) INTER=${OPTARG};;
		r) REP=${OPTARG};;
	esac
done

# Check args

if [ $INTER -lt 0 ]
then
	echo "number interval can't be negative"
	exit
fi

if [ $REP -lt 0 ]
then
	echo "number of  repetition can't be negative"
	exit
fi

# Process

read -p 'Do you want to see the result of checker ? [y] [n] ' RESULT

read -p 'Do you want to see the min score? [y] [n] ' MIN

read -p 'Do you want to see the max score? [y] [n] ' MAX
echo "\n"

AVERAGE=0
NB=0
MA=0
MI=0
I=0

for ((a=$REP; a>0; a--))
do
	ARG="`ruby -e "puts (0..$INTER).to_a.shuffle.join(' ')"`"
	./push_swap $ARG > test
	NB=$(cat test | wc -l)
	AVERAGE=$(expr $AVERAGE + $NB)

	if [ $MIN = "y" ]
	then
		if [ $I -eq 0 ]
		then
			MI=$NB
		fi

		if [ $MI -gt $NB ]
		then
			MA=$NB
		fi
	fi

	if [ $MAX = "y" ]
	then
		if [ $MA -lt $NB ]
		then
			MA=$NB
		fi
	fi

	if [ $RESULT = "y" ]
	then
		ok=$(cat test | ./checker $ARG)
		echo $ok
	fi
done

AVERAGE=$(expr $AVERAGE / $REP)

# Result

echo "\n"
for j in {17..21}
do
	echo "\033[48;5;${j}m     \033[0m\c"
done
echo "\033[7;49;31m   SCORE   \033[0m\c"
for j in {21..17}
do
	echo "\033[48;5;${j}m     \033[0m\c"
done

echo "\n\nOn \033[38;5;9m$REP\033[0m repetition with number between \033[38;5;9m0\033[0m and \033[38;5;9m$INTER\033[0m, the average is: \033[38;5;47m$AVERAGE\033[0m"
if [ $MAX = "y" ]
then
	echo "The max score is: \033[38;5;47m$MA\033[0m"
fi
if [ $MIN = "y" ]
then
	echo "The min score is: \033[38;5;47m$MI\033[0m"
fi
rm test
