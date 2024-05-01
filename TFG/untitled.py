import speech_recognition as sr
import pyphen

'''
* 
* Este programa en python lo que hace es recoger una frase ya sea por escrito o por voz de el
* usuario y escribirla en un fichero txt, no sin antes haber separado por sílabas cada palabra
* de la oración y haber puesto el símbolo "'" justo delante de cada sílaba tónica de cada palabra 
* del texto.
* Este programa en python es complementario a uno en c++
* 
'''



'''
* 
* Función obtener_texto
* Parámetros de entrada: 
* Parámetros de salida: 
* 
* Esta función lo que hace es preguntar al usuario si desea pasarle una oración
* o bien mediante texto escrito o bien mediante voz.
* 
'''
def obtener_texto():
    print("¿Deseas hablar o escribir? (hablar/escribir)")
    opcion = input().lower()

    if opcion == 'hablar':
        return obtener_texto_por_voz()
    elif opcion == 'escribir':
        return obtener_texto_por_escrito()
    else:
        print("Opción no válida.")
        return None

'''
* 
* Función obtener_texto_por_voz
* Parámetros de entrada: 
* Parámetros de salida: string
* 
* Esta función lo que hace es recoger el texto que el usuario le pase al programa mediante
* reconocimiento de voz, es decir, to que diga el usuario hablado se pasará a un string.
* 
'''
def obtener_texto_por_voz():
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("Di algo...")
        recognizer.adjust_for_ambient_noise(source)  # Ajusta el ruido ambiental
        audio = recognizer.listen(source)

    try:
        print("Reconociendo...")
        texto = recognizer.recognize_google(audio, language='es-ES')
        return texto
    except sr.UnknownValueError:
        print("No se pudo entender lo que dijiste.")
        return None
    except sr.RequestError as e:
        print("Error en la solicitud a la API de reconocimiento de voz; {0}".format(e))
        return None

'''
* 
* Función obtener_texto_por_voz
* Parámetros de entrada: 
* Parámetros de salida: string
* 
* Esta función lo que hace es recoger el texto que el usuario le pase al programa mediante
* escritura.
* 
'''
def obtener_texto_por_escrito():
    print("Por favor, escribe algo:")
    texto = input()
    return texto

'''
* 
* Función separar_silabas_con_tonica
* Parámetros de entrada: string
* Parámetros de salida: String
* 
* Esta función lo que hace es modificar un string, que será una palabra en castellano,
* que se le pase para que al encontrar la sílaba tónica de esa palabra ponga el símbolo
* "'" justo delante de la sílaba tónica de la palabra, bien sea porque la palabra tiene
* una vocal con acento o que no la tenga, esta función hará lo mismo, pondrá el símbolo
* "'" delante de la sílaba tónica.
* 
'''
def separar_silabas_con_tonica(palabra):
    acento = False
    acento_silaba = False
    aguda = False
    salida = ""
    comilla = False
    
    for letra in palabra:
        if letra in ['á', 'é', 'í', 'ó', 'ú']:  # Verificamos si la letra tiene acento
            acento = True  # Si hay al menos una letra con acento en la palabra
    
    diccionario = pyphen.Pyphen(lang='es')  # Especificamos el idioma, en este caso, español
    silabas = diccionario.iterate(palabra)

    for silaba in silabas:
        if acento == False:
            ultima_letra = silaba[1][-1]  # Obtiene la última letra de la sílaba
            if aguda == True:
                if silaba[0]:
                    salida = silaba[0] + "'" + silaba[1]
                else:
                    salida = "'" + silaba
                comilla = True
                break
            else:
                if ultima_letra in ['a', 'e', 'i', 'o', 'u', 'n', 's']:
                    aguda = True
                    continue
                else:
                    salida = silaba[0] + "'" + silaba[1]
                    comilla = True
                break
        else:
            for letra in silaba[1]:
                if letra in ['á', 'é', 'í', 'ó', 'ú']:  # Verificamos si la letra tiene acento
                        acento_silaba = True  # Si hay al menos una letra con acento en la palabra
                
            if acento_silaba == True:
                salida = silaba[0] + "'" + silaba[1]
                comilla = True
                break

        
    if comilla == False:
        salida = "'" + palabra

    nueva_palabra = ""
    for letra in salida:
        if letra == 'á':
            nueva_palabra += 'a'
        elif letra == 'é':
            nueva_palabra += 'e'
        elif letra == 'í':
            nueva_palabra += 'i'
        elif letra == 'ó':
            nueva_palabra += 'o'
        elif letra == 'ú':
            nueva_palabra += 'u'
        else:
            nueva_palabra += letra
    
    return nueva_palabra  # Devolvemos el resultado


texto_obtenido = obtener_texto()
print("Texto obtenido:", texto_obtenido)

if texto_obtenido:
    palabras = texto_obtenido.split()  # Dividir el texto en palabras

    texto_modificado = ""  # Inicializar el texto modificado
    
    for palabra in palabras:
        palabra_modificada = separar_silabas_con_tonica(palabra)  # Obtener la versión modificada de la palabra
        texto_modificado += palabra_modificada + " "  # Agregar la palabra modificada al texto modificado

    print("Texto modificado:", texto_modificado)

    # Escribir el texto modificado en un archivo
    with open("entrada.txt", "w") as file:
        file.write(texto_modificado)
else:
    print("No se pudo obtener ningún texto.")


# Escribir el texto modificado en un archivo
with open("entrada.txt", "w") as file:
    file.write(texto_modificado)
