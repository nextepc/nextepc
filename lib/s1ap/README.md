cd lib/asn1c

# backup asn_internal.h
cp asn_internal.h asn_inter.h.backup

# copy files 
cp OPEN5GS_FOLDER/lib/asn1c/common/*.[ch] .
cp OPEN5GS_FOLDER/lib/asn1c/s1ap/*.[ch] .

# Update Makefile.am if required
Update lib/asn1/Makefil.am if files are added
