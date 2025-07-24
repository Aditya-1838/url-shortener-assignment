# utils.py

import string
import random
import re

# Characters allowed in short codes
ALPHANUMERIC_CHARS = string.ascii_letters + string.digits  

def generate_short_code(length=6):
    """Generate a random short code."""
    return ''.join(random.choices(ALPHANUMERIC_CHARS, k=length))

def is_valid_url(url):
    """Basic URL validation."""
   
    pattern = re.compile(
        r'^(http:\/\/|https:\/\/)?(www\.)?([a-zA-Z0-9-]+\.)+[a-zA-Z]{2,}.*$'
    )
    return re.match(pattern, url) is not None
