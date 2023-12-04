BEGIN{
        FS="|";
        s=0;
        avg=0;
        c=0;
}
NR>1{
        if($3=="ENG"){
                s=s+$4;
                c=c+1;
        }

}
END{
        printf("Avg in eng is: %d",s/c);
}