# 🛠️ Implementation Notes


**Note:**  
- If `python` does not work, use `python3` instead for running commands.  
- Get into the virtual environment before running any command.

## 📁 Structure

- `app/main.py`: Main Flask application containing route definitions (shorten, redirect, stats, health check).
- `app/models.py`: In-memory dictionary (`url_store`) for storing shortened URLs, creation timestamp, and click count.
- `app/utils.py`: Utility functions:
  - `generate_short_code()` → generates 6-character alphanumeric codes.
  - `is_valid_url()` → validates if the given URL is in a proper format.
- `tests/test_basic.py`: Contains 5 test cases using `pytest` and Flask’s test client.
- `requirements.txt`: All Python dependencies listed.
- `NOTES.md`: This documentation file.

**How to Run the App:**
 get into the virtual environment before running any command 
```bash
python3 -m flask --app app.main run
```

---

## 🎯 Design Choices

- **In-Memory Storage:**  
  No external database used — ideal for simplicity, speed, and ease of local testing.

- **Short Code Generation:**  
  Random 6-character alphanumeric codes generated via `random.choices()`.

- **Click Tracking & Timestamps:**  
  Each short URL tracks click count and stores a `created_at` timestamp via `datetime.utcnow()`.

- **RESTful API Design:**  
  Proper use of HTTP verbs and status codes. All responses are JSON-formatted for easy frontend integration.

- **Error Handling:**  
  Clear messages for:
  - Missing fields
  - Invalid URL format
  - Not-found short codes

- **Code Comments:**  
  Added Hinglish-style inline comments to explain key logic and decisions.

---

## ✅ Testing

**Framework:** `pytest` + Flask test client  
**Total Test Cases:** 5  
**Covered Functionality:**
- `GET /` → Health check
- `POST /api/shorten` → Valid URL shortening
- `POST /api/shorten` → Invalid URL case
- `GET /<short_code>` → Redirection logic
- `GET /api/stats/<short_code>` → Analytics data

**How to Run Tests:**

```bash
PYTHONPATH=. pytest
```
---

## 🤖 AI Usage

- Used Chat GPT for Assisting with Flask syntax during route creation and error handling.
- Used Chat GPT for Assisting in writing the test cases and fixing the minor error faced during the whole process.
- Fixing test case failures and refining response structures.
- Utilized Copilot for generating error handling logic and inline comments.
- AI helped in formatting Markdown documentation and ensuring clarity.

---
## 🕒 What Could I Have Done With More Time

- Integrate a persistent database (e.g., SQLite, PostgreSQL) for storing URLs and analytics.
- Add user authentication and authorization for managing personal links.
- Implement rate limiting and security features to prevent abuse.
- Build a frontend UI for easier interaction and visualization of stats.
- Add support for custom short codes.
- Deploy the service to a cloud provider (e.g., Heroku, AWS,Render).
- Improve analytics with more detailed tracking (e.g., referrer, geo-location).
- Write more comprehensive unit and integration tests.
