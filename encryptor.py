import base64

def main():
    print("--- Simple Text Encryptor ---")
    choice = input("Do you want to (E)ncrypt or (D)ecrypt? ").upper()
    
    if choice == 'E':
        text = input("Enter the text to encrypt: ")
        # تحويل النص إلى تشفير Base64
        encoded_bytes = base64.b64encode(text.encode("utf-8"))
        encoded_text = encoded_bytes.decode("utf-8")
        print(f"Encrypted Result: {encoded_text}")
        
    elif choice == 'D':
        text = input("Enter the text to decrypt: ")
        try:
            # فك تشفير النص
            decoded_bytes = base64.b64decode(text.encode("utf-8"))
            decoded_text = decoded_bytes.decode("utf-8")
            print(f"Decrypted Result: {decoded_text}")
        except Exception:
            print("Error: Invalid encrypted text.")
    else:
        print("Invalid choice!")

if __name__ == "__main__":
    main()
