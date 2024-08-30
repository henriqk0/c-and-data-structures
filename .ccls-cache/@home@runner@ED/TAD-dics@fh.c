int main() {
  char *s = "QUALQUER_COISA";
  int soma = 0;

  for (int i = 0; i < strlen(s); i++)
    soma = soma + s[i];

  return 0;
}