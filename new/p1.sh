
read -p "Enter the no. of elements" n

if [[ $n =~ ^[0-9]+$ ]]
then


        echo "Enter array elements"
        for((i=0;i<n;i++))
        do
                read a[$i]
        done
        echo "Array is: "
        for((i=0;i<n;i++))
        do

                echo ${a[$i]}
        done
else
        echo "Invalid"
fi