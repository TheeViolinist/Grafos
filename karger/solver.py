import os
import subprocess
import matplotlib.pyplot as plt







def main():
    
    os.system("make")
    for i in range(2):
        i += 1
        for j in range(3):
            j += 1
            file_name = f'graph_type{i}_{j}'
            print(f'Resolvendo o arquivo {file_name}')
            output = subprocess.check_output([f'./main in/{file_name} out/{file_name}'], stderr=subprocess.STDOUT, shell=True)
            # Decodifica a saída em formato de string
            output_str = output.decode('utf-8')
            results = output_str.rstrip().split('\n')
            print(results)
            data = list()
            x = list() #Abcissa de y e z
            y = list()
            z = list()

            for result in results:
                data = result.split(' ')
                x.append(float(data[0]))
                y.append(float(data[1]))
                z.append(float(data[2]))

            plt.figure()
            plt.plot(x,y,marker='o',color='blue',label='Karger')
            plt.plot(x,z,marker='s', color='red',label="Dumb")
            plt.xlabel("Iterações")
            plt.ylabel("Probabilidade (%)")
            plt.title("Curva de Probalidade(%) x Iterações, algoritmos de Karger e Dumb")
            plt.legend()
            plt.savefig(f'results/{file_name}.pdf')    
            plt.clf()
            print("Resolvido com sucesso")








if __name__ == "__main__":
    main()
