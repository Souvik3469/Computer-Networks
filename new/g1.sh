f="personal.dat"

add()
{
        read -p "Enter name: " name
        read -p "Enter phno: " ph
        echo "Enter password: "
        read -s pass
        echo "$name $ph $pass" >> f
}
show()
{
        echo "Enter password to search: "
        read -s p
        if(($(grep -c $p f)!=0))
        then
                awk -v pa="$p" '$3 ~ pa {print $1" "$2}' f
        else
                echo "Not found"
        fi
}
while((1))
do
        echo "1. ADD"
        echo "2. Show"
        echo "3. Exit"
        read c
        case "$c" in
                1)add ;;
                2)show ;;
                3)exit ;;
                *)echo "Invalid choice"
        esac
done
~       