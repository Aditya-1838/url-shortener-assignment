from flask import Flask, request, jsonify, redirect
from .utils import generate_short_code, is_valid_url
from .models import save_url_mapping, get_original_url, get_url_metadata

app = Flask(__name__)

# Check if the app is working
@app.route('/')
def health_check():
    return jsonify({
        "status": "healthy",
        "service": "URL Shortener API"
    })

# Check if API is running
@app.route('/api/health')
def api_health():
    return jsonify({
        "status": "ok",
        "message": "URL Shortener API is running"
    })

# Creates a short URL
@app.route('/api/shorten', methods=['POST'])
def shorten_url():
    data = request.get_json()

    if not data or 'url' not in data:
        return jsonify({"error": "Missing JSON body or 'url' field"}), 400

    original_url = data.get('url')

    if not is_valid_url(original_url):
        return jsonify({"error": "Invalid URL"}), 400

    short_code = generate_short_code()
    save_url_mapping(original_url, short_code)

    return jsonify({
        "short_code": short_code,
        "short_url": request.host_url + short_code
    }), 201  # Return 201 when URL is shortened

# Open the original URL using the short link
@app.route('/<short_code>')
def redirect_to_original(short_code):
    original_url = get_original_url(short_code)
    if original_url:
        return redirect(original_url)
    return jsonify({"error": "URL not found"}), 404

# Get stats for a short URL
@app.route('/api/stats/<short_code>')
def url_stats(short_code):
    metadata = get_url_metadata(short_code)
    if metadata:
        return jsonify({
            "url": metadata["original_url"],
            "short_url": request.host_url + short_code,
            "created_at": metadata["created_at"].isoformat() + "Z",
            "clicks": metadata["clicks"]
        })
    return jsonify({"error": "No stats found"}), 404

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
