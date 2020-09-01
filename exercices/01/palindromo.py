st = "Socorram me subi no onibus em marrocos"
st = st.replace(' ', '').lower()

if st[::-1] == st[0::]:
    print('True')
else:
    print('False')
