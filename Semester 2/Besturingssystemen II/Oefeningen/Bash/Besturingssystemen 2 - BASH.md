# Besturingssystemen 2 - BASH
## Patterns, expansions en het opzoeken van hulp
1.

```bash
cp     # Kopieëren van bestanden
dd     # Converteren en kopiëren van bestanden
ln     # Links tussen bestanden leggen
mktemp # Tijdelijke bestanden en directories maken
cat    # Samenvoegen van output en outprinten
touch  # De timestamp wijzigen van een bestand. Maakt een nieuw bestand indien dit niet bestaat
```
2.

```bash
tail -f /etc/passwd
```
3.

```bash
rm ./-rf
```
4.

```bash
wc -c < bestand
```
5. /
6.

```bash
Zal buffers forceren om zich leeg te maken. 
```

7.

```bash
fdisk -l                                # Informatie over de partities
dd if=/dev/sdb1 of=image.img            # Inhoud van /dev/SDB1 naar image.img plaatsen
mount image.img /mnt                    # Mounten van image
```
8.

```bash
dd if=/dev/sda of=mbr.img count=1       # Kopië maken, de buffergrootte is standaard 512 bytes
strings mbr.img                         # String representatie
od -tx1 mbr.img                         # Octale representatie
```
9.

```bash
find -ctime -1                            
```
10.

```bash
genisoimage -o etc.iso /etc
```
11.

```bash
genisoimage -J -o etc.iso /etc
```
12.

```bash
dir a*.*                              # Alles dat begint met een a en ergens een . heeft
dir a*                                # Alles dat begint met een a
dir *a                                # Alles dat eindigt met een a
dir a\*                               # Letterlijk het bestand of de folder a*
```
13.

```bash
printf "%s\n" [abcd]                     #enkel letters a, b, c en d
printf "%s\n" [!abcd]                    # alle letters behalve a tot d
printf "%s\n" [^abcd]                    # e
printf "%s\n" [a-d]                      # enkel letters van a tot d
printf "%s\n" [abcd]*[abcd]              # alles dat begint en eindigt met a, b, c of d
```
14.

```bash
printf "%s\n" [a-e]                     # enkel letters van a tot e
printf "%s\n" [a/-e]                     
printf "%s\n" [a\-e]                    
printf "%s\n" [!\!*]                    
```
15.

```bash
printf "%s\n" ?
```
16.

```bash
printf "%s\n" ??
```
17.

```bash
(1) ls *
(2) dir *
(3) printf "%s\n" *
(4) ls "*"
(5) printf "%s\n" "*"
Het eerste verschil tussen 1, 2 en 3 is dat 3 geen onderscheid maakt tussen bestanden of directories. 2
```
18.

```bash
ls abc*                      # Geen uitvoer aangezien er geen items aanwezig zijn in abc
printf "%s\n" abc*           # print abc aangezien er een folder is dat abc heet
```
19.

```bash
printf "%s\n" ???            # Alles dat exact drie karakters heeft
printf "%s\n" ??e            # Alles dat exact drie karakters heeft en eindigt met een e
printf "%s\n" ??             # Alles dat exact twee karakters heeft
In het geval dat er geen match is zal het letterlijk de vraagtekens zoeken
```
20.

```bash
printf "%4d\n" {0..9} {1,2}{0..9}
```
21.

```bash
printf "%4s\n" {{0..9},{a..f}}{{0..9..2},{a..f..2}}
```
22.

```bash
echo ~root/                     # /root/       
echo ~mail/                     # /var/mail/
echo ~{mail,root}/              # /var/mail /root/
Brace expansion neemt dus plaats voor tilde expansion
```
## Redirection, piping en filtering, process substitution en het commando find
23.

```bash
du /etc                           # Disk usage van elk bestand in de /etc folder
du /var > tmp.txt                 # De output van het du programma in tmp.txt steken
du /etc 1 > tmp.txt               # De output van het du programma in tmp.txt steken, zal niet werken omdat tmp.txt al bestaat
du /var >> tmp.txt                # De standaarduitvoer van het du programma in tmp.txt steken, zal wel werken aangezien we tmp.txt overschrijven (>>)
du /etc 1>>tmp.txt                # De standaarduitvoer van het du programma in tmp.txt steken, zal ook werken aagezien we tmp.txt overschrijven
> tmp.txt du /etc                 # De output van het du programma in tmp.txt steken, zal niet werken omdat tmp.txt al bestaat. Maakt niet uit of dat het (>) teken vooraan of achteraan staat
du /var > tmp1.txt > tmp2.txt     # Bash zal alleen de laatste omleiding opvullen met de outvoer van het du programma. tmp1.txt zal wel aangemaakt worden maar zal leeg zijn
```
24.

```bash
set -o noclobber       # Aanzetten van noclobber
echo test > tmp.txt    # Zal een bestand tmp.txt aanmaken met de string
echo test > tmp.txt    # Kan de string niet schrijven naar tmp.txt aangezien het bestand bestaat
echo test >| tmp.txt   # tmp.txt overschrijven met de string a.d.h.v. symbool (>|). Dit  staat gelijk aan tijdelijk noclobber uitzetten
set +o noclobber       # noclobber uitzetten
echo test > tmp.txt    # tmp.txt overschrijven met de string
set -C                 # Aanzetten van noclobber
echo test > tmp.txt    # Kan de string niet schrijven
echo test >| tmp.txt   # tmp.txt overschrijven
set +C                 # noclobber uitzetten
echo test > tmp.txt    # tmp.txt overschrijven
```
25.

```bash
du /etc              # Disk usage van de /etc folder
du /etc 1>tmp.txt    # De standaarduitvoer van het du programma schrijven naar tmp.txt
du /etc 2>>tmp.txt   # tmp.txt overschrijven met het standaard foutenkanaal van het du programma
du /etc > tmp1.txt 2 > tmp2.txt # tmp1.txt zal de standaarduitvoer van het du programma bevatten terwijl tmp2.txt het standaard foutenkanaal bevatten
```
26.

```bash
du /etc > /dev/null   # Zal de standaarduitvoer omleiden naar /dev/null en het standaard foutenkanaal naar de console printen
cat /dev/null         # Bevat niets
```
27.

```bash
cat /dev/null > test.txt # Er wordt een leeg bestand aangemaakt met als naam test.txt
```
28.

```bash
ln -s /dev/null logbestand
```
29.

```bash
du /etc >tmp.txt 2>&1  # Zal de standaard uitvoer en het foutenkanaal van het du programma in tmp.txt steken
du /etc 2>&1 >tmp.txt  # Zal de standaard uitvoer naar tmp.txt steken en het standaard foutenkanaal printen op de console
du /etc &>tmp.txt # Zal elk kanaal in tmp.txt steken
du /etc 2>tmp.txt >tmp.txt # ???
exec 3>tmp.txt ; du /etc >&3 2>&1 ; exec 3>&- # Kanaal 3 omleiden naar tmp.txt. Daarna de uitvoer van het du programma omleidein naar kanaal 3 en het foutenkanaal naar de standaard uitvoer. Kanaal 3 wordt dan afgesloten. In tmp.txt zal de standaard uitvoer en het foutenkanaal bevatten
```


30.

```bash
du /etc ; du /var  # Eerst de uitvoer van du /etc printen naar de console, dan de uitvoer van du /var 
du /etc ; du /var > tmp.txt  # De standaarduitvoer van du /var steken in tmp.txt
( du /etc; du /var; ) > tmp.txt # De standaarduitvoer van zowel du /etc als du /var in tmp.txt steken. Dit wordt uitgevoerd in een subshell. De ; is ook niet verplicht
{ du /etc; du /var; } > tmp.txt # De standaarduitvoer van zowel du /etc als du /var in tmp.txt steken
```
31.

```bash
printf "dit is een fout\n" 1>&2
```
32

```bash
du /etc 2>&1 1>/dev/null | wc        # Piping, wat aan de rechterkant van een pipe staat wordt ook uitgevoerd in een subshell
        # OF
wc < <(du /etc 2>&1 1>/dev/null)     # Process substitution
```
33.

```bash
head -n 6 bestand | tail -1             # 6de lijn
        # OF
tail -1 < <(head -n 6 bestand)
```
34.

```bash
tr -d '\r' < bestand > tijdelijk
cp tijdelijk bestand
```
35.

```bash
sort bestand | uniq -d
```
36.

```bash
grep -G# Basic
grep -E# Extended
grep -P # Perl
```
37.

```bash
grep -E 'C\-[a-z] *' TUTORIAL    # Zal alle CTRL combinaties matchen
grep -E '(C\-[a-z] *){2}' TUTORIAL # Zal twee opeenvolgende CTRL combinaties matchen
grep '\(C\-[a-z] *\)\{2\}' TUTORIAL # Zelfde als bovenstaande maar aangezien het Basic is  moeten tekens zoals ( en { voorafgegaan worden door een \
```
38.

```bash
grep -E '^.*$' TUTORIAL   # Zal heel het bestand matchen
grep -E '^\.*$' T*        # Zal enkel . matchen die in het begin van een bestand staat in alle bestanden die beginnen met een T. grep zal ook de output opsplitsen per bestand
```
39.

```bash
grep -v # De lijnen tonen die niet aan het patroon voldoen
grep -f FILE # In FILE zitten de patronen
```
40.

```bash
grep -E '^$' TUTORIAL | wc -l  # Zal het aantal lijnen in het bestand uitprinten
grep -Ev '^$' TUTORIAL         # Zal heel het bestand uitprinten, maar zonder matches
grep -E 'margin|direction' TUTORIAL | nl # grep zal de lijnen matchen waar er margin of  direction inkomt en nl zal deze lijnen dan nummeren
nl TUTORIAL | grep -E 'margin|direction' # nl zal eerst de lijnen nummeren in het TUTORIAL bestand, daarna zal grep in dit bestand zoeken naar lijnen met direction of margin. Het verschil is dat de matches gekleurd worden en dat de line nummers overgenomen worden van de uitvoer van nl
grep -E '^-+$' TUTORIAL | uniq -d # Zal de lijnen uitprinten die exact hetzelfde zijn. De waarschijnlijkheid dat er zo twee lijnen bestaan is heel klein
grep -E '^-+$' TUTORIAL | sort | uniq -d # Zal de lijnen uitprinten die exact hetzelfde  zijn. Hier is er wel uitvoer
grep -E '\--+' TUTORIAL | grep -Ev '^-+$'
```
41.

```bash
du /           # Zal heel de root directory uitprinten
du / | less    # Dit commando laat navigatie toe in de terminal van de uitvoer van een programma
du / | more    # Dit commando zal beginnen met het uitprinten totdat het terminal venster vol staat. Er wordt dan een prompt getoond om verder te gaan of niet.
du / | cat     # Zal heel de root directory uitprinten. Dit is zinloos aangezien du / juist hetzelfde kan zonder een ander commando uit te voeren
```
42.

```bash
cat .bash_history | grep man | wc -l
            # OF
wc -l < <(grep man < <(cat .bash_history))
```
43.

```bash
sort -t ':' -k4,4 /etc/passwd > ~/passwd
sort -t ':' -k3,3 /etc/group >  ~/group
```
44.

```bash
join -t ':' -1 3 -2 4 ~/group ~/passwd > joined
```
45.

```bash
sort -r -g -f -t ':' -k4,4 -k5,5 /etc/passwd > ~/passwd
```
46.

```bash
cut -d ':' -f 1 /etc/passwd
```
47.

```bash
tee -a bestand
```
48.

```bash
find /etc -name pass*
```
49.

```bash
find /etc -type d -name sh*
```
50

```bash
find /usr type -f -size +1M -printf "%s %p\n"
```
51.

```bash
find Documents/ -type f -ctime -336 -printf "%a %p\n" 
```
52.

```bash
find /usr -type f -name *.h -printf "%h\n" | sort | uniq
```
53.

```bash
find / -type d 2>&1 >/dev/null | cut -d " " -f2
```
54.

```bash
find /etc -type f -perm /u=rwx
```
## Shell Variables
55.

```bash
printf "PATH %s\n" $PATH # Print de PATH variabele uit
printf "dag %s\n" $dag   # Print "dag" uit
dag=jan                  # De variabele dag op jan instellen
printf "dag %s\n" $dag   # Print "dag jan" uit
set                      # Print alle variabelen uit
```
56.

```bash
echo '$date:' $date      # Print de variabele date
echo '${date}:' ${date}  # Print de variabele date
echo '$(date):' $(date)  # Voert het commando date uit
```

57.

```bash
een=1
twee=een
echo ${een}       # 1
echo ${twee}      # een
echo ${!twee}     # 1
echo ${$twee}     # Bad substitution
eval $twee=2
echo ${twee}      # een
echo ${!twee}     # 2
```

58.

```bash
PS1      # begin van uw prompt (root@x) enz
PS2      # Het teken als de prompt aangevult moet worden
SHLVL    # Het aantal keren een nieuwe instantie van bash gestart is 
RANDOM   # Genereert een willekeurig getal tussen 0 en 32767 bij het aanroepen
SECONDS  # Het aantal seconden dat de huidige shell aan het draaien is
PWD      # De huidige werkdirectory
```

59.

```bash
hashtag (#)
```

60.

```bash
$PATH .
```

61.

```bash
CDPATH=/etc:/bin
cd yyy/
```

62.

```bash
cd -
```

63.

```bash
read a b c d < bestand
```

64.

```bash
IFS=' ' read a b c d
IFS=':' read a b c d
IFS=',' read a b c d

./IFSscript.sh < /etc/passwd
```

65.

```bash
IFS=':' 
x=ik:ben:groot; 
echo x=$x;
echo x="$x";
echo x='$x'; 
grep -E ^x= < <(set); 
grep -E ^x < <(set); 
declare -p x; 
declare -p ${!x*}
```
66.

```bash
t=$(du /etc/passwd)                        # t bevat de uitvoer van du
t=$(cut -f1 < <(du /etc/passwd))           # eerste kolom van uitvoer van du
t=$(cut -f1 < <(wc -l /etc/passwd))        # alle kolommen van uitvoer van wc
t=$(cut -d " " -f2 < <(wc -l /etc/passwd)) # tweede kolom van uitvoer van wc
t=$(wc -l < /etc/passwd)                   # uitvoer van wc
tab=($(wc -l  /etc/passwd))                # een array met 1 element, de uitvoer van wc
echo ${tab[1]}                             # lege string
```
## Arithmetic Expansion
67.

```bash
x=5
y=6
z=$(( x * y ))
    # of
let z=x*y
```

68.

```bash
time=$SECONDS; ls -IR / >/dev/null 2>&1; echo $(( $SECONDS - $time ))
```

## Argumenten van een script, positionele parameters en speciala parameters
69.

```bash
echo ${13}
# Vroeger
shift 4
echo $9
```

70.

```bash
x=13
echo ${!x}
```

71.

```bash
bash 71.sh 1 "" 3
```

72.

```bash
bash 72.sh {0..9}{a..f} 
```

73.

```bash
args=($@)
```

74.

```bash
bash 74a.sh arg1 arg2
```

75.

```bash
fac () {
    f=$1;
    index=1;
    res=1;
    while(($index < $f));
    do { 
       ((index++)); 
       res=$((res * index)); 
    }
    done;
    printf "%s\n" $res;
}
```

76.

```bash
wissel () {
    a=$1;
    b=$2;
    printf "Ervoor : %s - %s\n" $a $b 
    temp=$a;
    a=$b;
    b=$temp;
    printf 'Erna   : %s - %s\n' $a $b 
}
```

## Parameter Expansion
77.

```bash
aantal="${1:-10}"
```

78.

```bash
bash 78.sh 15
```

79.

```bash
x="/usr/share/emacs/24.5/tutorials/TUTORIAL.nl"
#BASH v1
echo ${x%/*}          # Directory
echo ${x##/*/}        # File
#BASH v2
file=${x/#*\//""} 
echo $file            # File
echo ${x/\/$file//""} # Directory
```

80.

```bash
x="dit is een <b>eenvoudige</b> en <b>nuttige</b> oefening"
#BASH V1
een=${x%%</*}
vet1=${een#*>}
rest=${x##*$vet1}
een=${rest%</*}
vet2=${een##*>}
echo "$vet1 *** $vet2"

#BASH v2
een=${x/<\/b>*/""}
vet1=${een/*<b>/""}
een=${x/*<b>/""}
vet2=${een/<\/b>*/""}
echo "$vet1 *** $vet2"
```

81.

```bash
echo ${@:$# - 1:1}
```

82.

```bash
1.
    x=$(($# - 1))
    echo ${!x}

2.
    eval echo ${??} # TODO
```

83.

```bash
echo ${data[@]}        # Alle getallen
echo ${#data[@]}       # Aantal getallen
echo ${data[2]}        # Index 2
echo ${data[5]}        # Index 5
echo ${data[20]}       # Index 20
```

84.

```bash
echo ${data[@]:2:1}
echo ${data[@]:5:1}
echo ${data[@]:20:1}
echo ${data[@]:(($# - 1)):1}   # Laatste element
```

85.

```bash
declare -a regel='([0]="43" [1]="72" [2]="2395" [3]="/etc/passwd")' # Inhoud
```

86.

```bash
echo ${!regel[@]}   # Opvragen indices
for i in ${!regel[@]}; do inv[${t[i]}]=$i; done  # Inverteren
```

87.

```bash
bash 87.sh $(date +%w)
```
88.

```bash
bash 88.sh
```

89.

```bash
bash 89.sh /etc/passwd
```

90.

```bash
IFS=$IFS:
```

91.

```bash
for i in $(cut -d : -f3 /etc/passwd); do ./91.sh $i; done # Alle uids overlopen
```

92.

```bash
bash 92.sh /etc/passwd 15
```

93.

```bash
while :; do echo "ok"; done
```

94.

```bash
bash 94.sh 
```

95.

```bash

```

96.

```bash

```

97.

```bash

```