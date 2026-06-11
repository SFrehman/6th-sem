# --------------"""List"""----------------
fruits = ["apple", "banana", "cherry"]  # Creates a mutable, ordered sequence
fruits[1] = "blueberry"                 # Changes the element at index 1
fruits.append("orange")                 # Adds a new element to the end

# --------------"""tuple"""----------------
coordinates = (10, 20, 30)              # Creates an immutable, ordered sequence
x = coordinates[0]                      # Accesses the element at index 0

# --------------"""dictionary"""----------------
user = {"name": "Alex", "role": "admin"} # Creates key-value pairs
user["role"] = "superadmin"             # Updates the value for an existing key
user["status"] = "active"               # Adds a new key and value

# --------------"""set"""----------------
tags = {"python", "code", "python"}     # Creates a collection of unique, unordered items
tags.add("dev")                         # Adds a new unique element