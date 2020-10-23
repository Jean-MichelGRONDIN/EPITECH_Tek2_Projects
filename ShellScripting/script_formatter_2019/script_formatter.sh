#! /bin/sh

exit_error() {
    echo $1 >&2;
    exit 84;
}

print_help() {
    echo "Usage:  script_formatter.sh in [-h] [-s] [-i nb_char] [-e] [-o out]";
    echo "";
    echo "     in                       input file";
    echo "   -h, --header              header generation";
    echo "   -s, --spaces              force spaces instead of tabulations for indentation";
    echo "   -i, --indentation=nb_char number of characters for indentation (8 by default)";
    echo "   -e, --expand              force do and then keywords on new lines";
    echo "   -o, --output=out          output file (stdout by default)";
    exit 0;
}

if [ $# == 0 ] ; then exit_error "No arguments founded !" ; fi
if [ $# == 1 ] && [ $1 == "-help" ] ; then print_help ; fi

INPUT_FILE="$1";
HEADER_MODE="no";
SPACES_MODE="no";
EXPAND_MODE="no";
IND_NB="8";
OUTPUT_FILE="no";

POSITIONAL=()
shift;
while [[ $# != "0" ]];
do
    key="$1"

    case $key in
        -h|--header)
        HEADER_MODE="yes"
        shift
        ;;
        -s|--spaces)
        SPACES_MODE="yes"
        shift
        ;;
        -e|--expand)
        EXPAND_MODE="yes"
        shift
        ;;
        -i)
        IND_NB="$2"
        shift
        shift
        ;;
        --indentation=*)
        TEMPO_TAB=($(echo "$1" | tr '=' '\n'))
        IND_NB="${TEMPO_TAB[1]}"
        shift
        ;;
        -o)
        OUTPUT_FILE="$2"
        shift
        shift
        ;;
        --output=*)
        TEMPO_TAB=($(echo "$1" | tr '=' '\n'))
        OUTPUT_FILE="${TEMPO_TAB[1]}"
        shift
        ;;
        *)
        exit_error "wrong argument detected !"
        ;;
    esac
done

if [ ! -f $INPUT_FILE ] || [ ! -r $INPUT_FILE ]; then
    exit_error "The file dosn't exist or miss read rights.";
fi

if [ $OUTPUT_FILE != "no" ] && [ -f $OUTPUT_FILE ] && [ ! -w $OUTPUT_FILE ]; then
    exit_error "Can't write in this file.";
fi

value=$(<$INPUT_FILE);

value=$(sed -rz 's/^[ |\n]*(#!)[ ]*\/bin\/([a-zA-Z0-9_]+)[ ]*[\n]+/\1 \/bin\/\2\n/g' <<< $value)

if IFS= LC_ALL=C read -rn2 -d '' shebang <<< $value && [ ! "$shebang" = '#!' ]; then
    value="#! /bin/sh
$value"
fi

if [ $EXPAND_MODE == "no" ]; then
    value=$(sed -rz 's/\ndo/do/g' <<< $value)
    value=$(sed -rz 's/\nthen/then/g' <<< $value)
else
    value=$(sed -rz 's/[^\n]do/\ndo/g' <<< $value)
    value=$(sed -rz 's/[^\n]then/\nthen/g' <<< $value)
fi

# [\n]{0,1}[ ]*([a-zA-Z_]+\([a-zA-Z]*\)[ |\n]*)\{[ ]*[\n]{0,1}([\[\] a-zA-Z0-9\t\-\"\:_\.\;\,\=\(\)\$\#\?\!\%\+\-\*\/\^\<\>\&\n]*)\}[ ]*[\n]{0,1}

if [ $OUTPUT_FILE = "no" ]; then
    echo "$value"
else
    echo "$value" >&"$OUTPUT_FILE"
fi