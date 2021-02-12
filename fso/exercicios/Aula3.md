# Exercícios
## 3. Diagrama de estados

![estados](./images/grafo-estados.png)

### 3.1. Na figura 1 são mostrados três estados de processos. Na teoria, com três estados poderia haver seis transições, duas para cada estado. Contudo, somente quatro transições são mostradas. Há alguma circunstância na qual uma delas ou ambas as transições não ilustradam possam ocorrer?

```
R: Não, um processo bloqueado por algum I/O só pode retornar ao executando depois de pronto, pois enquanto a operação de I/O está acontecendo o processador não pode continuar o processo.
```
