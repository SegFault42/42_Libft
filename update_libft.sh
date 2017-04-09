rm -fr *.c
rm -fr Makefile
rm -fr ft_dprintf
rm -fr includes

echo "type the new libft path: "
read NEW_LIBFT_PATH


cp -fr "$NEW_LIBFT_PATH"/*.c .
cp -fr "$NEW_LIBFT_PATH"/Makefile .
cp -fr "$NEW_LIBFT_PATH"/ft_dprintf .
cp -fr "$NEW_LIBFT_PATH"/includes .
