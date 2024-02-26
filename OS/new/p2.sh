a=("$@")
n=$#
echo "No.of elements are"
echo $n
echo "Array is"
for((i=0;i<n;i++))
do
        echo ${a[$i]}
done

echo $1

for((i=0;i<n-1;i++))
do
        mn=${a[$i]}
        idx=$i
        for((j=i+1;j<n;j++))
        do
                if((a[j] < mn))
                then
                        mn=${a[$j]}
                        idx=$j
                fi
        done

                        t=${a[$i]}
                        a[$i]=${a[$idx]}
                        a[$idx]=$t


done
echo "Sorted"
for((i=0;i<n;i++))
do
        echo ${a[$i]}
done