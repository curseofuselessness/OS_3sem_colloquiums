from flask import Flask, jsonify, abort, request, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('dashboard.html')

# ========== ОБРАБОТЧИКИ ОШИБОК ==========

@app.errorhandler(404)
def not_found(error):
    return jsonify({
        "status": "error",
        "message": error.description
    }), 404

@app.errorhandler(400)
def bad_request(error):
    return jsonify({
        "status": "error", 
        "message": error.description
    }), 400

@app.errorhandler(500)
def internal_error(error):
    return jsonify({
        "status": "error",
        "message": "Internal server error"
    }), 500


# ========== ЗАПУСК ==========

if __name__ == '__main__':
    print("🚀 To-Do API запущен!")
    print("🛑 Остановить: Ctrl+C")
    app.run(host='0.0.0.0', port=5000, debug=True)

