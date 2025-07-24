import pytest
from app.main import app

# Create a reusable client for testing
@pytest.fixture
def client():
    app.config['TESTING'] = True  # Enable testing mode
    with app.test_client() as client:
        yield client  # Return test client for each test

# Test the health check endpoint
def test_health_check(client):
    response = client.get('/')
    assert response.status_code == 200
    data = response.get_json()
    assert data['status'] == 'healthy'
    assert data['service'] == 'URL Shortener API'

# Test shortening a valid URL
def test_shorten_url(client):
    response = client.post('/api/shorten', json={'url': 'https://example.com'})
    assert response.status_code == 201
    data = response.get_json()
    assert 'short_code' in data
    assert 'short_url' in data

# Should return 400 error for an invalid URL
def test_shorten_invalid_url(client):
    response = client.post('/api/shorten', json={'url': 'not_a_valid_url'})
    assert response.status_code == 400
    data = response.get_json()
    assert 'error' in data

# Test analytics for a valid short_code
def test_analytics_for_valid_id(client):
    shorten_resp = client.post('/api/shorten', json={'url': 'https://example.com'})
    short_code = shorten_resp.get_json()['short_code']

    analytics_resp = client.get(f'/api/stats/{short_code}')
    assert analytics_resp.status_code == 200
    data = analytics_resp.get_json()
    assert data['url'] == 'https://example.com'
    assert 'clicks' in data
    assert 'created_at' in data

# Should return 404 for an invalid short_code
def test_analytics_for_invalid_id(client):
    response = client.get('/api/stats/invalidid123')
    assert response.status_code == 404
    data = response.get_json()
    assert 'error' in data
