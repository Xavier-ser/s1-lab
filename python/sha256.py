import hashlib

data = "hello"

hash_value = hashlib.sha256(data.encode()).hexdigest()

print(hash_value)