from datetime import datetime

# In-memory store to save short URL data
url_store = {}

def save_url_mapping(original_url, short_code):
    """Save the URL mapping with metadata."""
    # When a URL is shortened, store the original URL, creation time, and click count
    url_store[short_code] = {
        "original_url": original_url,
        "created_at": datetime.utcnow(),
        "clicks": 0
    }

def get_original_url(short_code):
    """Retrieve original URL and update click count."""
    # If the short code exists, increase the click count and return the original URL
    data = url_store.get(short_code)
    if data:
        data['clicks'] += 1
        return data['original_url']
    return None

def get_url_metadata(short_code):
    """Return metadata for a given short URL."""
    # Metadata includes the original URL, creation time, and the number of clicks
    return url_store.get(short_code)
